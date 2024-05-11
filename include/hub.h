#include "room.h"
#include "lobby.h"
#include <set>
#include <vector>
#include <memory>

/*
inherits:
join
leave
deliverAll
deliver
*/

class Hub : public Room
{

public:
	std::shared_ptr<Lobby> findLobby(std::string id) const;
	void joinLobby(Lobby& lobby, conn_ptr conn);

private:
	std::set<std::string> usernames_;
	std::set<conn_ptr> lobbiless_conns;
	std::set<conn_ptr> all_conns;
	std::vector<Lobby> lobbies_;

	bool usernameExist(std::string) const;
}
