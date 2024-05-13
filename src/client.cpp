#include "asio.hpp"
#include "message.hpp"
#include "client.hpp"
#include <cstdlib>
#include <deque>
#include <iostream>
#include <memory>
#include <utility>


using asio::ip::tcp;

Client::Client(asio::io_context& io_context, tcp::resolver::results_type& endpoints)
    : io_{io_context}, socket_(io_context), buffer_ {"None" , 'M'}
{
  Connect(endpoints);
}

void Client::deliver(message message_)
{
  message_.encode_header();
  asio::post(io_, 
    [this, message_]
    {
      bool is_curr_writing = !msgQ_.empty();
      msgQ_.push_back(message_);
      if (!is_curr_writing)
      {
        Write();
      }
    });
}

void Client::close()
{
  std::cout << "closing connection...\n";
  is_connected = false;
  asio::post(io_,
    [this]()
    {
      socket_.close();
    }
  );
}

void Client::Connect(tcp::resolver::results_type endpoints)
{
  asio::async_connect(socket_, endpoints,
    [this](std::error_code ec, tcp::endpoint)
    {
      if (!ec)
      {
        std::cout << "Successfully connected!\n";
        ReadHeader();   // begin reading
      }
    });
}

void Client::ReadHeader()
{
  buffer_.data_.resize(buffer_.header_length);    // size of the header
  asio::async_read(socket_, asio::buffer(buffer_.data(), buffer_.header_length),
  [this](std::error_code ec, size_t len)
  {
    if (!ec)
    {
      buffer_.decode_header();
      ReadBody();
    }
    else 
    {
      std::cout << "Reading Header Error: " << ec.message() << "\n";
      close();
    }
  });
}

void Client::ReadBody()
{
  asio::async_read(socket_, asio::buffer(buffer_.data(), buffer_.body_length()),
    [this](std::error_code ec, size_t len)
    {
      if (!ec)
      {
        std::cout << buffer_.data_ << "\n";
        ReadHeader();
      }
      else
      {
        std::cout << "Reading Body error: " << ec.message() << "\n";
        close();
      }
    });
}

void Client::Write()
{
  asio::async_write(socket_, asio::buffer(msgQ_.front().data_),
  [this](std::error_code ec, size_t len)
  {
    if (!ec)
    {
      msgQ_.pop_front();
      if (!msgQ_.empty())
      {
        Write();
      }
    }
    else
    {
      std::cout << "Writing error: " << ec.message() << "\n";
      close();
    }
  });
}
