#pragma once

#include "IO.hpp"
#include <string>
#include <stdexcept>

class FILEReader : public IO {
private:
    FILE *file;
    bool open;
    bool file_ends;

public:
    FILEReader(const std::string &file_name);
    ~FILEReader();

    bool is_file_ends() const;
    bool is_open() const;
    void close();
    char read_char();
    int read_int();
    std::string read_string();
};

