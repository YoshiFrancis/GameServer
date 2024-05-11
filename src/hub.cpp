#include "hub.h"

void Hub::join(conn_ptr conn)  
{
	Room::join(conn);
	lobbiless_conns.insert(conn);
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
