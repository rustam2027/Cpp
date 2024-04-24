#pragma once

#include "IO.hpp"
#include "ReaderWriter.h"
#include <cstddef>
#include <string>

class StringReaderWriter : public ReaderWriter{
  std::string* string_;
  bool open_;
  bool file_ends_;
  size_t pos;

public:
  StringReaderWriter(std::string* string);

  bool is_open() const;
  bool is_file_ends() const;
  void close();

  char read_char();
  int read_int();
  std::string read_string();

  void write(char c);
  void write(int i);
  void write(const std::string& string);

  ~StringReaderWriter();
};

