#include "lobby.h"
#include <string>
#include <algorithm>

std::string Lobby::getId() const
{
	return id_;
}

void Lobby::join(conn_ptr conn) 
{
	Room::join(conn);
	//	app_->join(conn);
	usernames_.insert(conn->getUsername());
}

void Lobby::leave(conn_ptr conn) 
{
	Room::leave(conn);
	conn->changeRoom(hub_);
	connections_.erase(conn);
	app_->leave(conn);
}

void Lobby::startApp()
{
	app_->start();
	hasStarted_ = true;
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
