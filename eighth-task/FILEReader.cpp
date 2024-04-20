#include "IO.hpp"
#include <string.h>
#include <filesystem>


class FILEReader : public IO {
  FILE *file;
  bool open;
  bool file_ends;

public:
  explicit FILEReader(const std::string &file_name)
      : file(nullptr), open(false), file_ends(false) {
    file = fopen(file_name.c_str(), "r");
    if (file == nullptr) {
      throw std::runtime_error("Failed to open file");
    }
    open = true;
  }

  ~FILEReader() {
    if (open) {
      close();
    }
  }

  bool is_file_ends() const { return file_ends; }

  bool is_open() const { return open; }

  void close() {
    if (file != nullptr) {
      fclose(file);
      file = nullptr;
      open = false;
    }
  }

  char read_char() {
    char c;
    int result = fscanf(file, "%c", &c);
    if (result == EOF) {
      file_ends = true;
      return '\0';
    }
    return c;
  }

  int read_int() {
    int i;
    int result = fscanf(file, "%d", &i);
    if (result == EOF) {
      file_ends = true;
    }
    return i;
  }

  std::string read_string() {
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
};

