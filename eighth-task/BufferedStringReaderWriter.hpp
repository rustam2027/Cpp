#pragma once

#include "ReaderWriter.h"

#include <cstddef>
#include <string>

class BufferedStringReaderWriter: public ReaderWriter {
  std::string& string_;
  size_t string_pos;

  std::string read_buffer;
  size_t read_buffer_pos;

  std::string write_buffer;

  size_t buffer_size_;

  bool open;
  bool file_ends;
  bool buffer_ends;

  void update_buffer();
  void update_write_buffer(bool now);

public:
  BufferedStringReaderWriter(std::string& string);
  BufferedStringReaderWriter(std::string& string, size_t buffer_size);
  
  bool is_open() const;
  bool is_file_ends() const;
  void close();

  void write(int i);
  void write(char c);
  void write(const std::string& str);

  char read_char();
  int read_int();
  std::string read_string();
  
  ~BufferedStringReaderWriter();
};


