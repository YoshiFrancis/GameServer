#include "message.hpp"
#include <iostream>

message::message(std::string msg, char flag)
	: data_{ msg }, flag_ { flag }
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

const std::string message::body() const
{
  return data_;
}

std::string message::body()
{
  return data_;
}

void message::body(std::string msg)
{
	data_ = msg;
	body_length_ = data_.size();
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

char message::getFlag()
{
	return flag_;
}

char message::getFlag() const
{
	return flag_;
}

void message::setFlag(char flag)
{
	flag_ = flag;
}

void message::decode_header()
{
  std::string header = data_.substr(0, 4);
	flag_ = data_[4];
  body_length_ = std::stoi(header);
  data_.resize(body_length_);
}

void message::encode_header()
{
  std::string header(header_length, ' ');
  body_length_ = data_.length();
  std::sprintf(&header[0], "%4d", static_cast<int>(body_length_));
	header[4] = flag_;
  data_ = header + data_;
}
