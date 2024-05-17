#ifndef APPLICATION_H
#define APPLICATION_H

#include "room.h"
#include <set>

class Application : public Room
{
public:

	virtual void start() = 0;
	virtual void end() = 0;
	virtual void addConns(std::set<conn_ptr>& conns) = 0;
	virtual Application* createApplication() = 0;
	void leave(conn_ptr conn) override;
};

#endif
