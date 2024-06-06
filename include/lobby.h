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
	Lobby(  Hub& hub, std::string id, Application* app)
		: hub_ { hub }, id_ { id }
	{
		app_ = app->createApplication(this);
	}

public:
	std::string getId() const;
	void join(conn_ptr conn) override;
	void leave(conn_ptr conn) override;
	void handleMessage(message& msg, conn_ptr conn) override;
	void end();

private:
	std::set<std::string> usernames_;
	// std::set<conn_ptr> connections_; -- inherited from Room
	Hub& hub_;
	Application* app_;
	std::string id_;
	bool hasStarted_ = false;
	bool isClosed_ = false;

	void startApp();
	void closeLobby();
	void handleCommand(message& msg, conn_ptr conn) override;
	std::string getRoomInfo() override;
	std::string getCommands() override;
	void alert(std::string conn_msg) override;
};

#endif
