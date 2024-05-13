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
		if (conn->getUsername() != "")
		{
			std::cout << conn->getUsername() << " has left!\n";
		}
		else
		{
			std::cout << "Person has left!\n";
		}
    connections_.erase(conn);
}

void Room::deliverAll(message& msg, conn_ptr conn_sender)
{
    msg.encode_header();
    std::cout << connections_.size() << " number of connections to send to\n";
    for (auto conn : connections_)
    {
			if (conn->isPrompt("None") && conn != conn_sender)
			{
				conn->deliver(msg);
			}
    }
}

void Room::handleMessage(message& msg, conn_ptr conn)
{
	std::cout << msg.getFlag() << "\n";
	if (msg.getFlag() == 'M')
	{
		if (conn->getUsername() != "")
		{
			msg.body(conn->getUsername() + ": " + msg.body());
			deliverAll(msg, conn);
		}
		else
		{
			deliverAll(msg);
		}
	}
}
