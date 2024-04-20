#include <filesystem>
#include <string>

#include "FILEWriter.h"
#include "IO.hpp"

FILEWriter::FILEWriter(const std::string file_name)
    : file(nullptr), open(false) {
  file = fopen(file_name.c_str(), "w");
  if (file == nullptr) {
    throw std::runtime_error("Failed to open file");
  }
  open = true;
}

bool FILEWriter::is_open() const { return open; }

bool FILEWriter::is_file_ends() const { return false; }

void FILEWriter::close() {
  fclose(file);

  file = nullptr;
  open = false;
}

void FILEWriter::write(int i) { fprintf(file, "%d", i); }

void FILEWriter::write(char c) { fprintf(file, "%c", c); }

void FILEWriter::write(const std::string &string) {
  for (char c : string) {
    write(c);
  }
}

FILEWriter::~FILEWriter() {
  if (open) {
    close();
  }
}
