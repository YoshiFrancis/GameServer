#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <cstdlib>
#include <string>

class message
{
public:
	message(std::string msg, char flag = 'M'); 
	static constexpr std::size_t header_length = 5;
  std::string data_;

  message();
  const char* data() const;
  char* data();
  std::size_t length() const;
  const std::string body() const;
  std::string body();
  std::size_t body_length() const;
  void body_length(std::size_t new_length);
	char getFlag();
	char getFlag() const;
	void setFlag(char flag);
  void decode_header();
  void encode_header();

private:
  std::size_t body_length_;
	char flag_ = 'M';
};

#endif // MESSAGE_HPP
