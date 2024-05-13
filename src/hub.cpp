#include "hub.h"
#include <iostream>

static void handleResponse(message& msg, conn_ptr conn);

void Hub::join(conn_ptr conn)  
{
	Room::join(conn);
	lobbiless_conns.insert(conn);
	if (conn->getUsername() == "")
	{
		promptConnUsername(conn);
	} 
	else
	{
		message newMessage { "Server: " + conn->getUsername() + " has joined the hub!", 'M' };
		deliverAll(newMessage);
	}
}

void Hub::leave(conn_ptr conn)
{
	Room::leave(conn);
	lobbiless_conns.erase(conn);
	message newMessage { "Server: " + conn->getUsername() + " has left!", 'M'};
	deliverAll(newMessage);
}

std::shared_ptr<Lobby> Hub::findLobby(std::string id) 
{
	std::shared_ptr<Lobby> lobbyIt = nullptr;
	/*
	auto lobbyIt = std::find(lobbies_.begin(), lobbies_.end(), 
		[&id](Lobby& lobby)
		{
			return lobby.getId() == id;
		});
	*/
	for (auto lobby : lobbies_)
	{
		if (lobby.getId() == id)
		{
			lobbyIt = std::make_shared<Lobby>(lobby);
			break;
		}
	}
	if (lobbyIt == nullptr)
		return nullptr;
	else
		return lobbyIt;
}

void Hub::joinLobby(Lobby& lobby, conn_ptr conn)
{
	conn->changeRoom(lobby);
	lobbiless_conns.erase(conn);
}

bool Hub::doesUsernameExist(std::string name) const 
{
	if (usernames_.find(name) == usernames_.end())
		return false;
	else
		return true;
}

void Hub::promptConnUsername(conn_ptr conn)
{
	std::string question { "Server: Please enter a username!!!" };
	message msg { question, 'Q'};
	conn->setPrompt("Username");
	msg.encode_header();
	conn->deliver(msg);
}

void Hub::handleMessage(message& msg, conn_ptr conn)
{
	if (!conn->isPrompt("None"))
	{
		msg.setFlag('R');
	}
	if (msg.getFlag() == 'M')
	{
		Room::handleMessage(msg, conn);
	}
	else if (msg.getFlag() == 'R')
	{
		handleResponse(msg, conn);
	}
	else if (msg.getFlag() == 'J')
	{
		auto lobby = findLobby(msg.data_);
		joinLobby(*lobby, conn);
	}
	else if (msg.getFlag() == 'L')
	{
		leave(conn);
	}
}

void Hub::handleResponse(message& msg, conn_ptr conn)
{
	// list of current prompts for hub:
	// 'Username'

	if (conn->isPrompt("Username"))
	{
		std::string username { msg.data_ };
		if (!doesUsernameExist(username))
		{
			conn->setUsername(username);
			usernames_.insert(username);
			std::cout << conn->getUsername() << " has joined the hub!\n";
			message newMsg { "Server: " + conn->getUsername() + " has declared himself!", 'M' };
			conn->setPrompt("None");
			deliverAll(newMsg);
		}
	}
}
