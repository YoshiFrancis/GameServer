#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <deque>
#include <iostream>
#include "asio.hpp"
#include "message.hpp"

using asio::ip::tcp;

class Client
{
public:
  Client(asio::io_context& io_context, tcp::resolver::results_type& endpoints);
  void deliver(message message_);
  void close();

public:
  bool is_connected = true;

private:
  void Connect(tcp::resolver::results_type endpoints);
  void ReadHeader();
  void ReadBody();
  void Write();

  asio::io_context& io_;
  tcp::socket socket_;
  std::deque<message> msgQ_;
  message buffer_;
};

#endif // CLIENT_HPP
