#ifndef ROOM_H
#define ROOM_H

#include "ConnectionI.hpp"
#include <set>

class message;

typedef std::shared_ptr<ConnectionI> conn_ptr;

class Room
{
public:
    virtual void join(conn_ptr conn);
    virtual void leave(conn_ptr conn);
    virtual void deliverAll(message& msg);

protected:
    std::set<conn_ptr> connections_;
};

#endif
