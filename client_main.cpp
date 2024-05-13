#include "asio.hpp"
#include "client.hpp"
#include <iostream>
#include <thread>
#include <string>

using asio::ip::tcp;

int main(int argc, char* argv[])
{

  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: chat_client <host> <port>\n";
      return 1;
    }

    asio::io_context io_context;
    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(argv[1], argv[2]);
    Client c(io_context, endpoints);
    std::thread t([&io_context](){ io_context.run(); });
    std::string input{};
    while (std::getline(std::cin, input) && c.is_connected)
    {
      message msg(input, 'M');
      c.deliver(msg);
    }
    if (c.is_connected)
      c.close();
    t.join();
  }
  catch(const std::exception& e)
  {
    std::cerr << "Error" << e.what() << '\n';
  }
  return 1;
  
}
