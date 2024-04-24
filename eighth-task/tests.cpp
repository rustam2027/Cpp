#include "FILEReaderWriter.h"
#include "BufferedFILEReaderWriter.h"
#include "StringReaderWriter.h"
#include "BufferedStringReaderWriter.hpp"

#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>

void reset_file() {
  FILE* file = fopen("in.txt", "w");
  fprintf(file, "%s", "Some text");
  fclose(file);
}

void check_file() {
  std::ifstream file("in.txt");
  std::string str;

  std::getline(file, str);

  assert(str == "Some textAnother text");
}

void test_1() {
  reset_file();

  FILEReaderWriter test_object("in.txt");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Some text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.write("Some textAnother text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.close();

  assert(test_object.is_open() == false);
  assert(test_object.is_file_ends() == true);

  check_file();
}

void test_2() {
  reset_file();

  BufferedFILEReaderWriter test_object("in.txt");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Some text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.write("Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.close();

  assert(test_object.is_open() == false);
  assert(test_object.is_file_ends() == true);

  check_file();
}

void test_3() {
  std::string str("Some text");

  StringReaderWriter test_object(&str);

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Some text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.write("Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.close();

  assert(test_object.is_open() == false);
  assert(test_object.is_file_ends() == true);

  assert(str == "Some textAnother text");
}

void test_4() {
  std::string str("Some text");

  BufferedStringReaderWriter test_object(str);

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Some text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.write("Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == false);

  assert(test_object.read_string() == "Another text");

  assert(test_object.is_open() == true);
  assert(test_object.is_file_ends() == true);

  test_object.close();

  assert(test_object.is_open() == false);
  assert(test_object.is_file_ends() == true);

  assert(str == "Some textAnother text");
}
