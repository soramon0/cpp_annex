#include "ScalarConverter.hpp"
#include "Parser.hpp"
#include "Printer.hpp"

void ScalarConverter::convert(const std::string &val) {
  if (Printer::tryPrintPseudo(val))
    return;

  if (Parser::isChar(val)) {
    char c = 0;
    if (Parser::parseChar(val, c)) {
      Printer::printScalars(c, static_cast<double>(static_cast<int>(c)),
                            static_cast<float>(c), static_cast<double>(c));
      return;
    }
  } else if (Parser::isFloat(val)) {
    float f = 0.0f;
    if (Parser::parseFloat(val, f)) {
      Printer::printScalars(static_cast<char>(f), static_cast<double>(f), f,
                            static_cast<double>(f));
      return;
    }
  } else if (Parser::isDouble(val)) {
    double d = 0.0;
    if (Parser::parseDouble(val, d)) {
      Printer::printScalars(static_cast<char>(d), d, static_cast<float>(d), d);
      return;
    }
  } else if (Parser::isInt(val)) {
    int i = 0;
    if (Parser::parseInt(val, i)) {
      Printer::printScalars(static_cast<char>(i), static_cast<double>(i),
                            static_cast<float>(i), static_cast<double>(i));
      return;
    }
  }

  Printer::printAllImpossible();
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}
