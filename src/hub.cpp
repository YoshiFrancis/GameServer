#include "hub.h"

static void handleResponse(message& msg, conn_ptr conn);

void Hub::join(conn_ptr conn)  
{
	Room::join(conn);
	lobbiless_conns.insert(conn);
}

void Hub::leave(conn_ptr conn)
{
	Room::leave(conn);
	lobbiless_conns.erase(conn);
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
	conn->changeRoom(std::make_shared<Lobby>(lobby));
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
	std::string question { "Please enter a username!!!" };
	message msg { question, 'Q'};
	conn->setPrompt("Username");
	conn->deliver(msg);
}

void Hub::handleMessage(message& msg, conn_ptr conn)
{
	if (msg.getFlag() == 'M')
	{
		deliverAll(msg);
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
		}
	}
}
