#pragma once

#include "ReaderWriter.h"

#include <cstddef>
#include <string>

class FILEReaderWriter : public ReaderWriter {
  FILE* file;
  bool open;
  bool file_ends;

  int file_writing_pos = 0;
  int file_reading_pos = 0;

public:
  FILEReaderWriter(const std::string filename);
  
  bool is_open() const;
  bool is_file_ends() const;
  void close();

  void write(int i);
  void write(char c);
  void write(const std::string& str);

  char read_char();
  int read_int();
  std::string read_string();
  
  ~FILEReaderWriter();
};
