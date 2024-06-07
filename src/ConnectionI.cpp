#include "ConnectionI.hpp"
#include "asio.hpp"
#include <iostream>
#include <memory>

using asio::ip::tcp;

ConnectionI::ConnectionI(Room* room)
  : room_(room)
{
}

std::string ConnectionI::getUsername()
{
	return username_;
}

void ConnectionI::setUsername(std::string username)
{
	username_ = username;
}

void ConnectionI::setPrompt(std::string prompt)
{
	std::cout << "Changing prompt of " << getUsername() << " to " << prompt << "\n";
	curr_prompt_ = prompt;
}

bool ConnectionI::isPrompt(std::string prompt)
{
	return prompt == curr_prompt_;
}

std::string ConnectionI::getPrompt()
{
	return curr_prompt_;
}
