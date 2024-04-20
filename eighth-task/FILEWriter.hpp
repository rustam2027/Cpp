#pragma once

#include "IO.hpp"
#include <string.h>
#include <filesystem>
#include <stdexcept>

class FILEWriter : public IO {
private:
    FILE *file;
    bool open;

public:
    FILEWriter(const std::string file_name);
    ~FILEWriter() override;

    bool is_open() const override;
    bool is_file_ends() const override;
    void close() override;
    void write(int i);
    void write(char c);
    void write(const std::string &str);
};

