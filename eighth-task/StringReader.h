#pragma once

#include "IO.hpp"
#include <string>

class StringReader : public IO {
  std::string::iterator string_iterator;
  std::string::iterator string_ends;
  bool open;
  bool file_ends;

public:
  StringReader(std::string string);
  bool is_open() const;
  bool is_file_ends() const;
  void close();
  char read_char();
  int read_int();
};
