#include "asio.hpp"
#include "message.hpp"
#include "room.h"
#include <deque>
#include <memory>


using asio::ip::tcp;

class Connection : public std::enable_shared_from_this<Connection>, public ConnectionI
{
public:
    Connection(tcp::socket socket, Room& room);
    void start();
    void deliver(message msg);

private:
    tcp::socket socket_;
    Room& room_;
    std::deque<message> messageQ_;
    message buffer_;

    void ReadHeader();
    void ReadBody();
    void Write();
};
