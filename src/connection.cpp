#include "connection.h"
#include <iostream>
#include <memory>

using asio::ip::tcp;


Connection::Connection(tcp::socket socket, Room* room)
  : socket_(std::move(socket)), buffer_{"None", 'M'}, ConnectionI(room)
{
}

void Connection::start()
{
  room_->join(shared_from_this());
  ReadHeader();
}

void Connection::deliver(message msg)
{
  bool is_curr_writing = !messageQ_.empty();
  messageQ_.push_back(msg); if (!is_curr_writing)
  {
    Write();
  }
}

void Connection::ReadHeader()
{
  auto self(shared_from_this());
  buffer_.data_.resize(buffer_.header_length);    // size of the header
  asio::async_read(socket_, asio::buffer(buffer_.data(), buffer_.header_length),
  [this, self](std::error_code ec, size_t len)
  {
      if (!ec)
      {
        buffer_.decode_header();
        ReadBody();
      }
      else 
      {
        std::cout << "Reading Header Error: " << ec.message() << "\n";
        room_->leave(shared_from_this());
      }
  });
}

void Connection::ReadBody()
{
  auto self(shared_from_this());
  asio::async_read(socket_, asio::buffer(buffer_.data(), buffer_.body_length()),
  [this, self](std::error_code ec, size_t len)
  {
		if (!ec)
		{
			std::cout << buffer_.data_ << "\n";
			room_->handleMessage(buffer_, shared_from_this());
			ReadHeader();
		} 
		else
		{
			std::cout << "Reading error: " << ec.message() << "\n";
			room_->leave(shared_from_this());
		}
  });
}

void Connection::Write()
{
  auto self(shared_from_this());
  asio::async_write(socket_, asio::buffer(messageQ_.front().data_),
  [this, self](std::error_code ec, size_t)
  {
		if (!ec)
		{
			messageQ_.pop_front();
			if (!messageQ_.empty())
			{
			Write();
			}
		}
		else
		{
			std::cout << "Write error: " << ec.message() << "\n";
			room_->leave(shared_from_this());
		}
  });
}
