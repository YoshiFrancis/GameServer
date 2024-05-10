#include "message.hpp"

class ConnectionI 
{
public:
    virtual ~ConnectionI() {}
    virtual void deliver(message msg) = 0;
};