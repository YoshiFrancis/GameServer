#include "room.h"
#include "lobby.h"

class Hub : public Room
{


private:
	std::set<std::string> usernames_;
	std::vector<conn_ptr> lobbiless_conns;
	std::vector<conn_ptr> all_conns;
	std::vector<lobby> lobbies_;
}
