#ifndef ROOM_H
#define ROOM_H

#include "ConnectionI.hpp"
#include <set>

class message;

typedef std::shared_ptr<ConnectionI> conn_ptr;

class Room
{
public:
    void join(conn_ptr conn);
    void leave(conn_ptr conn);
    void deliverAll(message& msg);

private:
    std::set<conn_ptr> connections_;
};

#endif
