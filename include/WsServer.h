#ifndef WSSERVER_H
#define WSSERVER_H

#include "hub.h"
#include "wsconnection.h"
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <asio.hpp>

#include <iostream>
#include <string>

using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;
using asio::ip::tcp;

class WsServer {
	
public:
	WsServer()
	void run(uint16_t port);
	
	typedef std::map<connection_hdl,std::owner_less<wsconnection>> con_map;

private:
	server server_;
	Hub& hub_;
	con_map connections_;
	void on_message(connection_hdl hdl, server::message_ptr msg);
	void on_open(connection_hdl hdl);
	void on_close(connection_hdl hdl);
}
