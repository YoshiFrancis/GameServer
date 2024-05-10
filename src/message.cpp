#include "message.hpp"

message::message()
    : body_length_(0)
{
}

const char* message::data() const
{
  return data_.data();
}

char* message::data()
{
  return &data_[0];
}

std::size_t message::length() const
{
  return header_length + body_length_;
}

const char* message::body() const
{
  return data_.data() + header_length;
}

char* message::body()
{
  return &data_[0] + header_length;
}

std::size_t message::body_length() const
{
  return body_length_;
}

void message::body_length(std::size_t new_length)
{
  body_length_ = new_length;
  data_.resize(header_length + body_length_);
}

void message::decode_header()
{
  std::string header = data_.substr(0, 4);
  body_length_ = std::stoi(header);
  data_.resize(body_length_);
}

void message::encode_header()
{
  std::string header(header_length, ' ');
  body_length_ = data_.length();
  std::sprintf(&header[0], "%4d", static_cast<int>(body_length_));
  data_ = header + data_;
}
