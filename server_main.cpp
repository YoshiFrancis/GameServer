#include "asio.hpp"
#include "server.h"
#include "WsServer.h"
#include "CardGame.h"
#include <iostream>

using asio::ip::tcp;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cout << "Usage: <port>\n";
    }

		CardGame cardgame { nullptr };
		std::vector<Application*> applications { &cardgame };
    asio::io_context io_context;
    tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[1]));
		Hub hub{ applications };
    Server server(io_context, endpoint, hub);
		WsServer wsserver(hub);
		wsserver.run(3001);
    io_context.run();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}
