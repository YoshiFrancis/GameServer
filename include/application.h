#ifndef APPLICATION_H
#define APPLICATION_H

#include "room.h"
#include "lobby.h"
#include <set>

class Lobby;

class Application : public Room
{
public:

	Application(Lobby& lobby)
		:  lobby_{ lobby }
	{ 
	}

	virtual void start() = 0;
	virtual void end() = 0;
	virtual void addClients(std::set<conn_ptr> conns) = 0;
	void leave(conn_ptr conn) override;

private:
	Lobby& lobby_;
};

#endif
