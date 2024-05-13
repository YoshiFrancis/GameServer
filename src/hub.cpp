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
		alert(conn->getUsername() + " has joined the hub!");
	}
}

void Hub::leave(conn_ptr conn)
{
	Room::leave(conn);
	lobbiless_conns.erase(conn);
	usernames_.erase(conn->getUsername());
	alert(conn->getUsername() + " has left!");
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
		handleResponse(msg, conn);
	} 
	else if (msg.getFlag() == 'C')
	{
		handleCommand(msg, conn);
	}
	else // default to message
	{
		Room::handleMessage(msg, conn);
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
			conn->setPrompt("None");
			alert(conn->getUsername() + " has declared himself!");
		}
	}
}

void Hub::handleCommand(message& msg, conn_ptr conn)
{
	if (msg.body().substr(0,5) == "/view")
	{
		std::string info = getRoomInfo();
		message info_msg { info, 'M' };
		info_msg.encode_header();
		conn->deliver(info_msg);
	}
	else if (msg.body().substr(0, 5) == "/help")
	{
		message command_msg { getCommands(), 'M' };
		command_msg.encode_header();
		conn->deliver(command_msg);
	}
	else if (msg.body().substr(0, 5) == "/join")
	{
		std::string lobby_id = msg.body().substr(6, msg.body_length());
		auto lobby = findLobby(lobby_id);
		joinLobby(*lobby, conn);
	}
	else if (msg.body().substr(0, 6) == "/leave")
	{
		leave(conn);
	}
	else if (msg.body().substr(0, 7) == "/create")
	{
		std::string lobby_id = msg.body().substr(8, msg.body_length());
		Lobby newLobby { *this, lobby_id };
		newLobby.join(conn);
		lobbies_.push_back(newLobby);
		alert("New lobby has been created by " + conn->getUsername() + " called " + lobby_id);
		// create lobby
	}
}

std::string Hub::getRoomInfo()
{
	std::string info_string{};
	info_string += Room::getRoomInfo();
	info_string += "\nTotal number of connections in hub: " + std::to_string(lobbiless_conns.size());
	info_string += "\nList of usernames of connections: ";
	std::for_each(usernames_.begin(), usernames_.end(), [&info_string](std::string username) { info_string += username + ", "; });
	info_string += "\nList of lobbies: ";
	std::for_each(lobbies_.begin(), lobbies_.end(), [&info_string](Lobby& lobby) { info_string += lobby.getId() + ", "; });
	return info_string;
}

std::string Hub::getCommands()
{
	std::string commands_string{"Server:"};
	commands_string += "\n/view : view the total number of connections, total connections not in a lobby, list of usernames, and list of currently active lobbies";
	commands_string += "\n/create <lobby name> : create a lobby with a specified lobby name";
	commands_string += "\n/join <lobby name> : join a lobby with a specified lobby name";
	commands_string += "\n/leave : leave hub and disconnect from server entirely";
	commands_string += "\n/help : view list of commands";
	return commands_string;
}

