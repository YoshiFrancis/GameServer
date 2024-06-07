#include "wsconnection.h"

wsconnection::wsconnection(WsServer& server, connection_hdl hdl, Room* room) : server_ { server }, hdl_ { hdl }, ConnectionI { room }
{ }

void wsconnection::deliver(message msg) {
	server_.deliver(hdl_, msg.data());
}

void wsconnection::changeRoom(Room* room)
{
	room_->leave(shared_from_this());
	room->join(shared_from_this());
	room_ = room;
}


void wsconnection::rcvMsg(std::string msg) {
	message message { msg };
	room_->handleMessage(message, shared_from_this());
}

void wsconnection::start() {
	room_->join(shared_from_this());
}
