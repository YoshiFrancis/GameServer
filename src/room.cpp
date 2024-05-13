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

void Room::handleCommand(message& msg, conn_ptr conn)
{
	if (msg.body().substr(0, 5) == "/view")
	{
		message info_msg { "Server:\n" + getRoomInfo(), 'M' };
		info_msg.encode_header();
		conn->deliver(info_msg);
	}
}

std::string Room::getRoomInfo()
{
	std::string info_string{};
	info_string += "Total number of connections: " + std::to_string(connections_.size());
	return info_string;
}

std::string Room::getCommands()
{
	std::string commands_string{ "/view" };
	commands_string += "/view : view the descriptions about the room";
	return commands_string;
}

void Room::alert(std::string conn_msg)
{
	message alert_msg { "Server: " + conn_msg, 'M' };
	deliverAll(alert_msg);
}
