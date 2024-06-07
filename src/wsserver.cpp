#include "WsServer.h"

WsServer::WsServer() {
	server_.set_access_channels(websocketpp::log::alevel::all);
	server_.clear_access_channels(websocketpp::log::alevel::frame_payload);
	
	server_.init_asio();

	server_.set_message_handler(&on_message, this, ::_1, ::_2);
	server_.set_open_handler(&on_open, this, ::_1);
	server_.set_close_handler(&on_close, this, ::_1);

}

void WsServer::run(uint16_t port) {
	server_.listen(port);
	server_.start_accept();
	server_.run();
}

void WsServer::on_message(connection_hdl hdl, server::message_ptr msg) {
	connections_[hdl]->rcvMsg(msg);
}

void WsServer::on_close(connection_hdl hdl) {
	connections_[hdl]->rcvMsg("/close");
	connections_.erase(hdl);
}

void WsServer::on_open(connection_hdl hdl) {
	wsconnection wsconn {  *this, hdl, &hub_ }l
	connections_[hdl] = wsconn;
}
