#include "room.h"

class Application : public Room
{
public:
	virtual void start();
	virtual void end();
	virtual void addConnections(std::set<conn_ptr>& connections);
}
