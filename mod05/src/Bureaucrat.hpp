#pragma once

#include <string>

typedef unsigned char u8;

class Bureaucrat {
private:
  std::string const name;
  u8 grade;

public:
  Bureaucrat();
  ~Bureaucrat();
};
