#pragma once

#include <string>

class Printer {
public:
  static bool tryPrintPseudo(const std::string &v);
  static void printScalars(char c, double intSource, float f, double d);
  static void printAllImpossible();

private:
  Printer();
  Printer(const Printer &other);
  Printer &operator=(const Printer &other);
  ~Printer();

  static void printPseudo(const char *floatLine, const char *doubleLine);
  static void printDecimal(const char *label, double value, const char *suffix);
};
