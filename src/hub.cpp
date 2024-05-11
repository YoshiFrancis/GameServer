#include "hub.h"

void join(conn_ptr conn) override 
{
	Room::join(conn);
	lobbiless_conns.insert(conn);
}

std::shared_ptr<Lobby> Hub::findLobby(std::string id)
{
	auto lobbyIt = std::find(lobbies_.begin(), lobbies_.end(), 
		[](Lobby& lobby)
		{
			return lobby.getId() == id;
		});
	if (lobbyIt == lobbies_.end())
		return nullptr;
	else
		return std::make_shared<Lobby>(*lobbyIt);
}

void joinLobby(Lobby& lobby, conn_ptr conn)
{
	conn.joinRoom(lobby);
	lobbiless_conns.erase(conn);
}

bool Hub::doesUsernameExist(std::string name) const 
{
	if (usernames_.find(name) == usernames_.end())
		return false;
	else
		return true;
}
