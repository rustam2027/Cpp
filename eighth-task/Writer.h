#pragma once

#include <string>
#include "IO.hpp"

class Writer : public IO {
  virtual void write(char c) = 0;
  virtual void write(int i) = 0;
  virtual void write(const std::string& str) = 0;
};
