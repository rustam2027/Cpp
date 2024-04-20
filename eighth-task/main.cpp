#include <iostream>

#include "FILEReader.hpp"
#include "FILEWriter.hpp"

int main() {
  try {
    FILEReader file("int.txt");
    std::cout << "File open: " << file.is_open() << std::endl;
    std::cout << "File ends: " << file.is_file_ends() << std::endl;

    std::cout << "Content: " << file.read_string() << std::endl;

    std::cout << "File open: " << file.is_open() << std::endl;
    std::cout << "File ends: " << file.is_file_ends() << std::endl;

    file.close();

    std::cout << "File open: " << file.is_open() << std::endl;
    std::cout << "File ends: " << file.is_file_ends() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
