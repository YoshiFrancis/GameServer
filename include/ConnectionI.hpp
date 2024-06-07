#ifndef CONNECTIONI_H
#define CONNECTIONI_H

#include "message.hpp"
#include <string>
#include <memory>

class Room;

class ConnectionI 
{
public:
		ConnectionI(Room* room);
    virtual ~ConnectionI() {}
    virtual void deliver(message msg) = 0;
		virtual void changeRoom(Room* room);
		virtual std::string getUsername();
		virtual void setUsername(std::string name);
		virtual void setPrompt(std::string prompt);
		virtual bool isPrompt(std::string prompt);
		virtual std::string getPrompt();

protected:
	Room* room_;
	std::string username_;
	std::string curr_prompt_;
};

typedef std::shared_ptr<ConnectionI> conn_ptr;

#endif
