#ifndef SERVER_HPP
#define SERVER_HPP

#include "asio.hpp"
#include "hub.h"

using asio::ip::tcp;

class Server
{
public:

    Server(asio::io_context& io_context, tcp::endpoint& endpoint, std::vector<Application*>& applications);
    void Accept();

private:
    tcp::acceptor acceptor_;
    Hub hub_;
};

#endif // SERVER_HPP
