#ifndef ROOM_H
#define ROOM_H

#include "ConnectionI.hpp"
#include "message.hpp"
#include <set>


class Room
{
public:
		Room() = default;
    virtual void join(conn_ptr conn);
    virtual void leave(conn_ptr conn);
    virtual void deliverAll(message& msg, conn_ptr conn_sender = nullptr);
		virtual void handleMessage(message& msg, conn_ptr conn);
		virtual void handleCommand(message& msg, conn_ptr conn);
		virtual std::string getRoomInfo();
		virtual std::string getCommands();
		virtual void alert(std::string message);
		virtual void signalRoomTermination();

protected:
		Room(std::set<conn_ptr>& conns) : connections_ (conns) {}
    std::set<conn_ptr> connections_;
		Room* return_room_ = nullptr;
};

#endif
