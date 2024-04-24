#include <iostream>

// #include "IO.hpp"
// #include "FILEReader.h"
// #include "FILEWriter.h"
// #include "ReaderWriter.h"
// #include "StringReader.h"
// #include "StringWriter.h"
#include "FILEReaderWriter.h"
// #include "StringReaderWriter.h"
// #include "BufferedFILEReaderWriter.h"
#include "BufferedStringReaderWriter.hpp"
#include "tests.hpp"

#include <random>
#include <string>

// void test_reader() {
//   try {
//     FILEReader file("int.txt");
//     std::cout << "File open: " << file.is_open() << std::endl;
//     std::cout << "File ends: " << file.is_file_ends() << std::endl;

//     std::cout << "Content: " << file.read_string() << std::endl;

//     std::cout << "File open: " << file.is_open() << std::endl;
//     std::cout << "File ends: " << file.is_file_ends() << std::endl;

//     file.close();

//     std::cout << "File open: " << file.is_open() << std::endl;
//     std::cout << "File ends: " << file.is_file_ends() << std::endl;
//   } catch (const std::exception &e) {
//     std::cerr << "Exception: " << e.what() << std::endl;
//   }
// }

// void test_writer() {
//   try {
//     FILEWriter file("out.txt");
//     std::cout << "File open: " << file.is_open() << std::endl;
//     std::cout << "File ends: " << file.is_file_ends() << std::endl;

//     file.write("123");

//     std::cout << "File open: " << file.is_open() << std::endl;
//     std::cout << "File ends: " << file.is_file_ends() << std::endl;

//     file.close();

//     std::cout << "File open: " << file.is_open() << std::endl;
//     std::cout << "File ends: " << file.is_file_ends() << std::endl;
//   } catch (const std::exception &e) {
//     std::cerr << "Exception: " << e.what() << std::endl;
//   }
// }

// void test_string_reader() {
//   StringReader reader("asdf4");
//   std::cout << "String open: " << reader.is_open() << std::endl;
//   std::cout << "String ends: " << reader.is_file_ends() << std::endl;

//   std::cout << "Read char: " << reader.read_char() << std::endl;
//   std::cout << "Read char: " << reader.read_char() << std::endl;
//   std::cout << "Read char: " << reader.read_char() << std::endl;
//   std::cout << "Read char: " << reader.read_char() << std::endl;

//   std::cout << "Read int: " << reader.read_int() << std::endl;

//   std::cout << "String open: " << reader.is_open() << std::endl;
//   std::cout << "String ends: " << reader.is_file_ends() << std::endl;

//   reader.close();

//   std::cout << "String open: " << reader.is_open() << std::endl;
//   std::cout << "String ends: " << reader.is_file_ends() << std::endl;
// }

// void test_string_writer() {
//   std::string str = "1234";
//   StringWriter writer(&str);

//   std::cout << "String open: " << writer.is_open() << std::endl;
//   std::cout << "String ends: " << writer.is_file_ends() << std::endl;

//   writer.write('a');

//   std::cout << "New string: " << str << std::endl;

//   writer.write("asd1");

//   std::cout << "New string: " << str << std::endl;

//   writer.write(123);

//   std::cout << "New string: " << str << std::endl;
  
//   std::cout << "String open: " << writer.is_open() << std::endl;
//   std::cout << "String ends: " << writer.is_file_ends() << std::endl;

//   writer.close();

//   std::cout << "String open: " << writer.is_open() << std::endl;
//   std::cout << "String ends: " << writer.is_file_ends() << std::endl;
  
// }

void test_file_reader_writer() {
  FILEReaderWriter reader_writer("out.txt");

  std::cout << reader_writer.read_string() << std::endl;

  reader_writer.write('1');

  std::cout << reader_writer.read_string() << std::endl;

  reader_writer.close();
}

// void test_string_reader_writer() {
//   std::string str = "out.txt";
//   StringReaderWriter reader_writer(&str);

//   reader_writer.write(10);
  
//   std::cout << reader_writer.read_string() << std::endl;

//   reader_writer.write("123");

//   std::cout << reader_writer.read_string() << std::endl;

//   std::cout << str << std::endl;
  
//   reader_writer.close();
// }

// void test_buffered_file_reader_writer() {
//   BufferedFILEReaderWriter reader_writer("out.txt");

//   std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;

//   std::cout << reader_writer.read_char() << std::endl;

//   std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;

//   reader_writer.write("2");

//   std::cout << reader_writer.read_string() << std::endl;

//   std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;

//   std::cout << reader_writer.read_string() << std::endl;

//   std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;
  

//   reader_writer.close();
// }

void test_buffered_string_reader_writer() {
  std::string str = "out.txt\n";
  BufferedStringReaderWriter reader_writer(str);

  std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;

  std::cout << reader_writer.read_char() << std::endl;

  std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;

  reader_writer.write("2");

  std::cout << reader_writer.read_string() << std::endl;

  std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;

  std::cout << reader_writer.read_string() << std::endl;

  std::cout << "Is file ends: " << reader_writer.is_file_ends() << std::endl;
  

  reader_writer.close();
}

int main() {
  // test_reader();
  // test_writer();
  // test_string_reader();
  // test_string_writer();
  // test_file_reader_writer();
  // test_string_reader_writer();
  // test_buffered_file_reader_writer();
  // test_buffered_string_reader_writer();
  test_1();
  test_2();
  test_3();
  test_4();
  
  return 0;
}
