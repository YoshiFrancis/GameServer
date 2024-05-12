#ifndef HUB_H
#define HUB_H

#include "room.h"
#include "lobby.h"
#include <set>
#include <vector>
#include <memory>

/*
inherits:
join
leave
deliverAll
deliver
*/

class Lobby;

class Hub : public Room
{

public:
	std::shared_ptr<Lobby> findLobby(std::string id);
	void joinLobby(Lobby& lobby, conn_ptr conn);
	void join(conn_ptr conn) override;
	void leave(conn_ptr conn) override;
	void promptConnUsername(conn_ptr conn);
	void handleMessage(message& msg, conn_ptr conn) override;

private:
	std::set<std::string> usernames_;
	std::set<conn_ptr> lobbiless_conns;
	std::vector<Lobby> lobbies_;
	// inherits std::set<conn_ptr> connections_ from room

	bool doesUsernameExist(std::string name) const;
	void handleResponse(message& msg, conn_ptr conn);
};

#endif