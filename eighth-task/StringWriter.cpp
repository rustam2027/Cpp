#include "StringWriter.h"
#include <string>

StringWriter::StringWriter(std::string *string) : string_(string), open(true) {}

bool StringWriter::is_open() const { return open; }

bool StringWriter::is_file_ends() const { return false; }

void StringWriter::close() { open = false; string_ = nullptr; }

void StringWriter::write(char c) { string_->push_back(c); }

void StringWriter::write(const std::string &str) {
  for (char c : str) {
    write(c);
  }
}

void StringWriter::write(int i) {
  std::string number = std::to_string(i);
  write(number);
}
