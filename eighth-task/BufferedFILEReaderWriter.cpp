#include "BufferedFILEReaderWriter.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

BufferedFILEReaderWriter::BufferedFILEReaderWriter(const std::string filename,
                                                   size_t buffer_size)
    : file(nullptr), open(false), file_ends(false), buffer_size_(buffer_size),
      buffer_ends(false) {
  file = fopen(filename.c_str(), "r+");
  if (file == nullptr) {
    throw std::runtime_error("Cannot open file");
  }
  open = true;

  update_buffer();
}

BufferedFILEReaderWriter::BufferedFILEReaderWriter(const std::string filename)
    : BufferedFILEReaderWriter(filename, 16) {}

void BufferedFILEReaderWriter::update_buffer() {
  read_buffer_pos = 0;
  read_buffer.clear();
  if (file_ends) {
    return;
  }
  for (size_t i = 0; i < buffer_size_; i++) {
    char c;
    char result = fscanf(file, "%c", &c);
    if (result == EOF) {
      buffer_ends = true;
      break;
    }

    read_buffer.push_back(c);
  }
  if (read_buffer.empty()) {
    file_ends = true;
  }
}

BufferedFILEReaderWriter::~BufferedFILEReaderWriter() {
  if (open) {
    close();
  }
}

bool BufferedFILEReaderWriter::is_file_ends() const { return file_ends; }

bool BufferedFILEReaderWriter::is_open() const { return open; }

void BufferedFILEReaderWriter::close() {
  if (file != nullptr) {
    update_write_buffer(true);

    fclose(file);
    file = nullptr;
    open = false;
  }
}

char BufferedFILEReaderWriter::read_char() {
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

int BufferedFILEReaderWriter::read_int() { return read_char() - '0'; }

std::string BufferedFILEReaderWriter::read_string() {
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

void BufferedFILEReaderWriter::write(int i) { write(std::to_string(i)); }

void BufferedFILEReaderWriter::write(char c) {
  write_buffer.push_back(c);
  update_write_buffer(false);
  file_ends = false;
  buffer_ends = false;
}

void BufferedFILEReaderWriter::write(const std::string &string) {
  for (char c : string) {
    write(c);
  }
}

void BufferedFILEReaderWriter::update_write_buffer(bool now) {
  if (write_buffer.size() < buffer_size_ && !now) {
    return;
  }
  long current_pos = ftell(file);
  fprintf(file, "%s", write_buffer.c_str());
  fseek(file, current_pos, SEEK_SET);

  write_buffer.clear();
}

