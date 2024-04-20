#include <iostream>

#include "FILEReader.h"
#include "FILEWriter.h"

void test_reader() {
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
}

void test_writer() {
  try {
    FILEWriter file("out.txt");
    std::cout << "File open: " << file.is_open() << std::endl;
    std::cout << "File ends: " << file.is_file_ends() << std::endl;

    file.write("123");

    std::cout << "File open: " << file.is_open() << std::endl;
    std::cout << "File ends: " << file.is_file_ends() << std::endl;

    file.close();

    std::cout << "File open: " << file.is_open() << std::endl;
    std::cout << "File ends: " << file.is_file_ends() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}

int main() {
  test_writer();
  return 0;
}
