#pragma once

struct IO {
  virtual bool is_open() const = 0;
  virtual bool is_file_ends() const = 0;
  virtual void close() = 0;
  virtual ~IO() {}
};

