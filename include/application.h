#ifndef APPLICATION_H
#define APPLICATION_H

#include "room.h"
#include "lobby.h"

class Lobby;

class Application : public Room
{
public:

	Application(std::set<conn_ptr>& connections, Lobby& lobby)
		:  lobby_{ lobby }
	{ 
		connections_ = connections;
	}

	virtual void start() = 0;
	virtual void end() = 0;
	void leave(conn_ptr conn) override;

private:
	Lobby& lobby_;
};

#endif
