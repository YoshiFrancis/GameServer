#ifndef APPLICATION_H
#define APPLICATION_H

#include "room.h"
#include <set>
#include <string>

class Application : public Room
{
public:

	virtual void start(std::set<conn_ptr>& conns) = 0;
	virtual void end() = 0;
	virtual Application* createApplication() = 0;
	virtual std::string getDescription() = 0;
	void leave(conn_ptr conn) override;
};

#endif
