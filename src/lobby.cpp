#include "lobby.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>


std::string Lobby::getId() const
{
	return id_;
}

void Lobby::join(conn_ptr conn) 
{
	Room::join(conn);
	//	app_->join(conn);
	usernames_.insert(conn->getUsername());
	alert(conn->getUsername() + " is joining the lobby!\n");
}

void Lobby::leave(conn_ptr conn) 
{
	usernames_.erase(conn->getUsername());
	alert(conn->getUsername() + " is leaving the lobby!\n");
	conn->changeRoom(&hub_);
	// app_->leave(conn);
}

void Lobby::startApp()
{
	std::thread application_thread(
		[&]()
		{
			std::cout << "starting app...";
			app_->start(connections_);
		});
	hasStarted_ = true;
	application_thread.join();
	//endApp();
}

void Lobby::endApp()
{
	message msg { "Ending game"};
	deliverAll(msg);
	std::for_each(connections_.begin(), connections_.end(), [this](conn_ptr conn) { leave(conn); });
}

void Lobby::closeLobby()
{
	message msg { "Closing lobby. No one can join anymore." };
	deliverAll(msg);
	isClosed_ = true;
}

void Lobby::handleMessage(message& msg, conn_ptr conn)
{
	if (msg.getFlag() == 'C')
	{
		handleCommand(msg, conn);
	}
	else // default to message
	{
		Room::handleMessage(msg, conn);
	}
}

void Lobby::handleCommand(message& msg, conn_ptr conn)
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
	else if (msg.body().substr(0, 6) == "/start")
	{
		// ....
		alert("Starting game!");
		startApp();
	}
	else if (msg.body().substr(0, 6) == "/leave")
	{
		conn->changeRoom(&hub_);
	}
}

std::string Lobby::getRoomInfo()
{
	std::string info_string{};
	info_string += Room::getRoomInfo();
	info_string += "\nGame type: " + app_->getDescription();
	info_string += "\nList of usernames of connections: ";
	std::for_each(usernames_.begin(), usernames_.end(), [&info_string](std::string username) { info_string += username + ", "; });
	return info_string;
}

std::string Lobby::getCommands()
{
	std::string commands_string{"Server:"};
	commands_string += "\n/view : view total connections not in a lobby, list of usernames, and game held in lobby";
	commands_string += "\n/start : start the application. Can only be used by the host (one who started the lobby)";
	commands_string += "\n/leave : leave lobby and join back hub";
	commands_string += "\n/help : view list of commands";
	return commands_string;
}

void Lobby::alert(std::string conn_msg)
{
	message alert_msg { "Lobby: " + conn_msg, 'M' };
	deliverAll(alert_msg);
}
