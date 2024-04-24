#include "FILEReaderWriter.h"
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/_types/_seek_set.h>

FILEReaderWriter::FILEReaderWriter(const std::string filename)
    : file(nullptr), open(false), file_ends(false){
  file = fopen(filename.c_str(), "r+");
  if (file == nullptr) {
    throw std::runtime_error("Cannot open file");
  }

  open = true;
}

FILEReaderWriter::~FILEReaderWriter() {
  if (open) {
    close();
  }
}

bool FILEReaderWriter::is_file_ends() const { return file_ends; }

bool FILEReaderWriter::is_open() const { return open; }

void FILEReaderWriter::close() {
  if (file != nullptr) {
    fclose(file);
    file = nullptr;
    open = false;
  }
}

char FILEReaderWriter::read_char() {
  char c;
  fseek(file, file_reading_pos, SEEK_SET);
  int result = fscanf(file, "%c", &c);
  if (result == EOF) {
    file_ends = true;
    return '\0';
  }
  file_reading_pos += result;
  return c;
}

int FILEReaderWriter::read_int() {
  int i;
  fseek(file, file_reading_pos, SEEK_SET);
  int result = fscanf(file, "%d", &i);
  if (result == EOF) {
    file_ends = true;
  }
  file_reading_pos += result;
  return i;
}

std::string FILEReaderWriter::read_string() {
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

void FILEReaderWriter::write(int i) { write(std::to_string(i)); }

void FILEReaderWriter::write(char c) {
  file_ends = false;

  fseek(file,file_writing_pos, SEEK_SET);
  int result = fprintf(file, "%c", c);
  file_writing_pos += result;
}

void FILEReaderWriter::write(const std::string &string) {
  for (char c : string) {
    write(c);
  }
}
