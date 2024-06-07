#ifndef WSCONNECTION_H
#define WSCONNECTION_H

#include "ConnectionI.hpp"
#include "WsServer.h"
#include <memory>

class wsconnection : public ConnectionI, public enable_shared_from_this<wsconnection>
{

public:
	wsconnection(WsServer& server, connection_hdl hdl, Room* room);
	void deliver(message msg) override;

private:
	WsServer& server_;
	connection_hdl hdl;

};
