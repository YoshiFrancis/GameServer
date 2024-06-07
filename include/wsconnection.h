#ifndef WSCONNECTION_H
#define WSCONNECTION_H

#include "ConnectionI.hpp"
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "WsServer.h"
#include <string>
#include <memory>

class WsServer;

using websocketpp::connection_hdl;

class wsconnection : public ConnectionI, public std::enable_shared_from_this<wsconnection>
{

public:
	wsconnection(WsServer& server, connection_hdl hdl, Room* room);
	void deliver(message msg) override;
	void changeRoom(Room* room) override;
	void rcvMsg(std::string msg);
	void start();

private:
	WsServer& server_;
	connection_hdl hdl_;

};

#endif
