#include "asio.hpp"
#include "message.hpp"
#include "room.h"
#include <deque>
#include <memory>


using asio::ip::tcp;

class Connection : public std::enable_shared_from_this<Connection>, public ConnectionI
{
public:
    Connection(tcp::socket socket, Room* room);
    void deliver(message msg) override;
    void start();
		void joinRoom(Room& room);

private:
    tcp::socket socket_;
    std::deque<message> messageQ_;
    message buffer_;

    void ReadHeader();
    void ReadBody();
    void Write();
};
