#ifndef ROOM_H
#define ROOM_H

#include "ConnectionI.hpp"
#include "message.hpp"
#include <set>


typedef std::shared_ptr<ConnectionI> conn_ptr;

class Room
{
public:
    virtual void join(conn_ptr conn);
    virtual void leave(conn_ptr conn);
    virtual void deliverAll(message& msg, conn_ptr conn_sender = nullptr);
		virtual void handleMessage(message& msg, conn_ptr conn);
		virtual void handleCommand(message& msg, conn_ptr conn);
		virtual std::string getRoomInfo();
		virtual std::string getCommands();
		virtual void alert(std::string message);

protected:
    std::set<conn_ptr> connections_;
};

#endif
