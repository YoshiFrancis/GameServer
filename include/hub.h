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

struct ApplicationType 
{
	Application& app;
	std::string description;
};

class Hub : public Room
{

public:
	
	Hub(std::vector<ApplicationType>& applications) 
		: applications_ { applications }
	{
	}

	Lobby* findLobby(std::string id);
	void joinLobby(Lobby& lobby, conn_ptr conn);
	void joinLobby(Lobby* lobby, conn_ptr conn);
	void join(conn_ptr conn) override;
	void leave(conn_ptr conn) override;
	void deliverAll(message& msg, conn_ptr conn_sender=nullptr) override;
	void promptConnUsername(conn_ptr conn);
	void handleMessage(message& msg, conn_ptr conn) override;
	void handleCommand(message& msg, conn_ptr conn) override;

private:
	std::set<std::string> usernames_;
	std::set<conn_ptr> lobbiless_conns;
	std::vector<Lobby> lobbies_;
	std::vector<ApplicationType> applications_;
	// inherits std::set<conn_ptr> connections_ from room

	bool doesUsernameExist(std::string name) const;
	void handleResponse(message& msg, conn_ptr conn);
	std::string getRoomInfo() override;
	std::string getCommands() override;
	void alert(std::string conn_msg) override;
};

#endif
