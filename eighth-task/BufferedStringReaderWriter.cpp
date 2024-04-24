#include "BufferedStringReaderWriter.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

BufferedStringReaderWriter::BufferedStringReaderWriter(std::string &string,
                                                       size_t buffer_size)
    : file_ends(false), buffer_size_(buffer_size), buffer_ends(false),
      string_(string), string_pos(0), open(true) {
  update_buffer();
}

BufferedStringReaderWriter::BufferedStringReaderWriter(std::string &string)
    : BufferedStringReaderWriter(string, 16) {}

void BufferedStringReaderWriter::update_buffer() {
  read_buffer_pos = 0;
  read_buffer.clear();
  if (file_ends) {
    return;
  }
  for (size_t i = 0; i < buffer_size_; i++) {
    if (string_pos == string_.size()) {
      buffer_ends = true;
      return;
    }

    char c = string_.at(string_pos++);

    read_buffer.push_back(c);
  }
  if (read_buffer.empty()) {
    file_ends = true;
  }
}

BufferedStringReaderWriter::~BufferedStringReaderWriter() {}

bool BufferedStringReaderWriter::is_file_ends() const { return file_ends; }

bool BufferedStringReaderWriter::is_open() const { return open; }

void BufferedStringReaderWriter::close() { open = false; }

char BufferedStringReaderWriter::read_char() {
  if (read_buffer_pos == read_buffer.size()) {
    update_write_buffer(true);
    update_buffer();
  }
  char c = read_buffer.at(read_buffer_pos++);
  if (read_buffer_pos == read_buffer.size()) {
    if (buffer_ends) {
      file_ends = true;
    } else {
      update_buffer();
    }
  }
  return c;
}

int BufferedStringReaderWriter::read_int() { return read_char() - '0'; }

std::string BufferedStringReaderWriter::read_string() {
  std::string line;
  char c;
  while (!file_ends) {
    c = read_char();
    if (c == '\0' || c == '\n') {
      break;
    }
    line.push_back(c);
  }
  return line;
}

void BufferedStringReaderWriter::write(int i) { write(std::to_string(i)); }

void BufferedStringReaderWriter::write(char c) {
  write_buffer.push_back(c);
  update_write_buffer(false);
  file_ends = false;
  buffer_ends = false;
}

void BufferedStringReaderWriter::write(const std::string &string) {
  for (char c : string) {
    write(c);
  }
}

void BufferedStringReaderWriter::update_write_buffer(bool now) {
  if (write_buffer.size() < buffer_size_ && !now) {
    return;
  }
  for (char c : write_buffer) {
    string_.push_back(c);
  }
  write_buffer.clear();
}
