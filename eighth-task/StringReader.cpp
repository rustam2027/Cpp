#include "IO.hpp"
#include <string>


class StringReader : public IO {
  std::string string_;
  bool open;

public:
  StringReader(std::string string): string_(string), open(true) {
    
  }
};
