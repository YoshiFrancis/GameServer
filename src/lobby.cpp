#include "lobby.h"
#include <string>

std::string getId() const
{
	return id_;
}

void Lobby::join(conn_ptr conn) override
{
	Room::join(conn);
	app_.join(conn);
}

void Lobby::leave(conn_ptr conn) override
{
	Room::leave(conn);
	conn.joinRoom(hub_);
	connections_.erase(conn);
	app_.leave(conn);
}

void Lobby::startApp()
{
	app_.start();
	hasStarted_ = true;
}

void Lobby::endApp()
{
	deliverAll("Ending game");
	std::for_each(connections_.begin(), connections_.end(), [](conn_ptr conn) { leave(conn); };
}

void Lobby::closeLobby()
{
	deliverAll("Closing lobby. No one can join.");
	isClosed_ = true;
}
