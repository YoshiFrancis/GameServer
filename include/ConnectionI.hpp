#include "message.hpp"
#include <memory>

class Room;

class ConnectionI 
{
public:
    virtual ~ConnectionI() {}
    virtual void deliver(message msg) = 0;
		virtual void changeRoom(std::shared_ptr<Room> room) = 0;
		virtual std::string getUsername() = 0;
};
