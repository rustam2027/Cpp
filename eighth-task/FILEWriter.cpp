#include "IO.hpp"
#include <string.h>
#include <filesystem>

class FILEWriter : public IO {
  FILE *file;
  bool open;

public:
  FILEWriter(const std::string file_name)
      : file(nullptr), open(false) {
    file = fopen(file_name.c_str(), "w");
    if (file == nullptr) {
      throw std::runtime_error("Failed to open file");
    }
    open = true;
  }

  bool is_open() const override { return open; }

  bool is_file_ends() const override { return true; }

  void close() override {
    fclose(file);

    file = nullptr;
    open = false;
  }

  void write(int i) { fprintf(file, "%d", i); }

  void write(char c) { fprintf(file, "%c", c); }

  void write(std::string string) {
    for (char c : string) {
      write(c);
    }
  }

  ~FILEWriter() {
    if (open) {
      close();
    }
  }
};

