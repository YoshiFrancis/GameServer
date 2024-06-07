#include "wsconnection.h"

wsconnection::wsconnection(WsServer& server, connection_hdl hdl, Room* room) : server_ { server }, hdl_ { hdl }, room_ { room }
{ }

void wsconnection::deliver(message msg) {
	server_.send(hdl, msg.data());
}

void wsconnection::rcvMsg(server::message_ptr msg) {
	room_->handleMessage(msg->get_payload(), shared_from_this());
}

void wsconnection::start() {
	room_->join(shared_from_this());
}
