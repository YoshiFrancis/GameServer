#include "asio.hpp"
#include "client.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>

using asio::ip::tcp;

// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
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
			ltrim(input);
			rtrim(input);
			message msg(input, 'M');
			if (input[0] == '/')
			{
				msg.setFlag('C');
			}
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
