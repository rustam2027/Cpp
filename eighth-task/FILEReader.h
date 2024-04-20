#pragma once

#include "IO.hpp"
#include <string.h>
#include <stdexcept>

class FILEReader : public IO {
private:
    FILE *file;
    bool open;
    bool file_ends;

public:
    explicit FILEReader(const std::string &file_name);
    ~FILEReader() override;

    bool is_file_ends() const override;
    bool is_open() const override;
    void close() override;
    char read_char();
    int read_int();
    std::string read_string();
};

