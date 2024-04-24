#pragma once

#include "IO.hpp"
#include <string>

class Reader : public IO {
  virtual char read_char() = 0;
  virtual int read_int() = 0;
  virtual std::string read_string() = 0;
};
