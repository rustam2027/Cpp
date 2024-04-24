#pragma once

#include "IO.hpp"
#include <string>

class StringWriter : public IO {
  std::string* string_;
  bool open;

public:
  StringWriter(std::string* string);
  bool is_open() const;
  bool is_file_ends() const;
  void close();

  void write(char c);
  void write(int i);
  void write(const std::string& string);
};
