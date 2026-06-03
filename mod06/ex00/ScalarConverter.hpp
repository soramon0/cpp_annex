#pragma once

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &val);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
};
