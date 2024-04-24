#include "StringReader.h"
#include "IO.hpp"

#include <string>

StringReader::StringReader(std::string string)
    : string_iterator(string.begin()), string_ends(string.end()), open(true), file_ends(false) {}

bool StringReader::is_open() const { return open; }

bool StringReader::is_file_ends() const { return file_ends; }

char StringReader::read_char() {
  char c = *string_iterator++;
  if (string_iterator == string_ends) {
    file_ends = true;
  }
  return c;
}

int StringReader::read_int() {
  int i = read_char() - '0';
  return i;
}

void StringReader::close() {
  open = false;
}
