#include "room.h"
#include "message.hpp"
#include <iostream>


void Room::join(conn_ptr conn)
{
    std::cout << "Someone has joined!\n";
    connections_.insert(conn);
}

void Room::leave(conn_ptr conn)
{
    std::cout << "Person has left!\n";
    connections_.erase(conn);
}

void Room::deliverAll(message& msg)
{
    msg.encode_header();
    std::cout << connections_.size() << " number of connections to send to\n";
    for (auto conn : connections_)
    {
        conn->deliver(msg);
    }
}

void Room::handleMessage(message& msg, conn_ptr conn)
{
	std::cout << msg.getFlag() << "\n";
	if (msg.getFlag() == 'M')
		deliverAll(msg);
}
