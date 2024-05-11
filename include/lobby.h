#include "room.h"
#include "hub.h"
#include "application.h"

/*
inherits from room:
join
leave
deliverall
deliver
*/

class lobby : public room
{

public:
	std::string getId() const;
	void join(conn_ptr conn) override;
	void leave(conn_ptr conn) override;

private:
	std::set<std::string> usernames_;
	std::set<conn_ptr> connections_;
	Hub& hub_;
	Application app_;
	std::string id_;
	bool hasStarted_ = false;
	bool isClosed_ = false;

	void startApp();
	void endApp();
	void closeLobby();
}
