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
    void deliver(message msg) override;
		void joinRoom(Room& room);
		void changeRoom(std::shared_ptr<Room> room) override;
		std::string getUsername() override;
		void setUsername(std::string) override;
		void setPrompt(std::string prompt) override;
		bool isPrompt(std::string prompt) override;

private:
    tcp::socket socket_;
    std::shared_ptr<Room> room_;
    std::deque<message> messageQ_;
    message buffer_;
		std::string username_;
		std::string curr_prompt_;

    void ReadHeader();
    void ReadBody();
    void Write();
};
