#pragma once

#include <string>

struct Symbol {
  enum Kind { NAN, NANF, INF_PLUS, INF_MINUS, INFF_PLUS, INFF_MINUS, UNKNWON };

public:
  static Kind getSymbol(const std::string &val);
};

class ScalarConverter {
public:
  static void convert(const std::string &val);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
};
