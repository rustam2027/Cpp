#include "StringReaderWriter.h"

StringReaderWriter::StringReaderWriter(std::string *string)
    : string_(string), open_(true), file_ends_(false), pos(0) {}

bool StringReaderWriter::is_open() const { return open_; }

bool StringReaderWriter::is_file_ends() const { return file_ends_; }

void StringReaderWriter::close() { string_ = nullptr; open_ = false; }

char StringReaderWriter::read_char() {
  if (pos == string_->size() - 1) {
    file_ends_ = true;
  }
  return string_->at(pos++);
}

int StringReaderWriter::read_int() { return read_char() - '0'; }

std::string StringReaderWriter::read_string() {
  std::string line;
  char c;
  while (!file_ends_) {
    c = read_char();
    if (c == '\0' || c == '\n') {
      break;
    }
    line.push_back(c);
  }
  return line;
}

void StringReaderWriter::write(char c) {
  string_->push_back(c);
  file_ends_ = false;
}

void StringReaderWriter::write(const std::string &str) {
  for (char c : str) {
    write(c);
  }
}

void StringReaderWriter::write(int i) {
  std::string number = std::to_string(i);
  write(number);
}

StringReaderWriter::~StringReaderWriter() {
  close();
}
