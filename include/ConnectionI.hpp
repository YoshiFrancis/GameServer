#include "message.hpp"
#include <memory>

class Room;

class ConnectionI 
{
public:
    virtual ~ConnectionI() {}
    virtual void deliver(message msg) = 0;
		virtual void changeRoom(Room& room) = 0;
		virtual std::string getUsername() = 0;
		virtual void setUsername(std::string name) = 0;
		virtual void setPrompt(std::string prompt) = 0;
		virtual bool isPrompt(std::string prompt) = 0;
};
