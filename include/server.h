#ifndef SERVER_HPP
#define SERVER_HPP

#include "asio.hpp"
#include "room.h"

using asio::ip::tcp;

class Server
{
public:
    Server(asio::io_context& io_context, tcp::endpoint& endpoint);
    void Accept();

private:
    tcp::acceptor acceptor_;
    Room room_;
};

#endif // SERVER_HPP
