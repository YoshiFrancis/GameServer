#ifndef LOBBY_H
#define LOBBY_H

#include "room.h"
#include "hub.h"
#include "application.h"
#include <memory>

/*
inherits from room:
join
leave
deliverall
deliver
*/

class Hub;
class Application;

class Lobby : public Room
{

public:
	Lobby(Hub& hub, conn_ptr host)
		: hub_ { hub }
	{
		join(host);
	}

public:
	std::string getId() const;
	void join(conn_ptr conn) override;
	void leave(conn_ptr conn) override;

private:
	std::set<std::string> usernames_;
	// std::set<conn_ptr> connections_; -- inherited from Room
	Hub& hub_;
	std::shared_ptr<Application> app_;
	std::string id_;
	bool hasStarted_ = false;
	bool isClosed_ = false;

	void startApp();
	void endApp();
	void closeLobby();
};

#endif
