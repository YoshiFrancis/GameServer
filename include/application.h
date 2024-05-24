#ifndef APPLICATION_H
#define APPLICATION_H

#include "room.h"
#include <set>
#include <string>

class Application : public Room
{
public:

	Application() = default;

	virtual void start(std::set<conn_ptr>& conns) = 0;
	virtual void end() = 0;
	virtual Application* createApplication(Room* room) = 0;
	virtual std::string getDescription() = 0;
	virtual void reset() = 0;
	void leave(conn_ptr conn) override;

protected:
	Application(Room* room) : return_room_ { room }
	{
	}

	Room* return_room_;
};

#endif
