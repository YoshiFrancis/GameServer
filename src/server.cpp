#include "server.h"
#include "connection.h"
#include <iostream>
#include <memory>

Server::Server(asio::io_context& io_context, tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint)
{
    Accept();
}

void Server::Accept()
{
    acceptor_.async_accept(
    [this](std::error_code ec, tcp::socket socket)
    {
        if (!ec)
        {
            std::cout << "Successful connection!\n";
            std::make_shared<Connection>(std::move(socket), hub_)->start();
            Accept();
        }
    });
}
