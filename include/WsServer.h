#ifndef WSSERVER_H
#define WSSERVER_H

#include "hub.h"
#include "wsconnection.h"
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <asio.hpp>

#include <iostream>
#include <string>
#include <map>

using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;
using asio::ip::tcp;

typedef websocketpp::server<websocketpp::config::asio> server;

class WsServer {
	
public:
	WsServer(Hub& hub);
	void run(uint16_t port);
	
	typedef std::map<connection_hdl,std::shared_ptr<wsconnection>> con_map;

private:
	server server_;
	Hub& hub_;
	con_map connections_;
	void on_message(connection_hdl hdl, server::message_ptr msg);
	void on_open(connection_hdl hdl);
	void on_close(connection_hdl hdl);
};

#endif
