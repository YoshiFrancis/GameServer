#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <cstdlib>
#include <string>

class message
{
public:
  static constexpr std::size_t header_length = 4;
  std::string data_;

  message();
  const char* data() const;
  char* data();
  std::size_t length() const;
  const char* body() const;
  char* body();
  std::size_t body_length() const;
  void body_length(std::size_t new_length);
  void decode_header();
  void encode_header();

private:
  std::size_t body_length_;
};

#endif // MESSAGE_HPP
