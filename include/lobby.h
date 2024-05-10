#include "room.h"
#include "hub.h"
#include "application.h"

class Lobby : public Room
{


private:
	std::set<std::string> usernames_;
	std::set<conn_ptr> connections_;
	std::shared_ptr<hub> hub_;
	Application app_;
}
