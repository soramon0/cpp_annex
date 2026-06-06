#include "Printer.hpp"
#include <climits>
#include <cctype>
#include <iomanip>
#include <iostream>

Printer::Printer() {}

Printer::Printer(const Printer &other) { (void)other; }

Printer &Printer::operator=(const Printer &other) {
  (void)other;
  return *this;
}

Printer::~Printer() {}

void Printer::printAllImpossible() {
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: impossible\n";
  std::cout << "double: impossible" << std::endl;
}

void Printer::printPseudo(const char *floatLine, const char *doubleLine) {
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: " << floatLine << "\n";
  std::cout << "double: " << doubleLine << std::endl;
}

bool Printer::tryPrintPseudo(const std::string &v) {
  if (v == "nan" || v == "nanf") {
    printPseudo("nanf", "nan");
    return true;
  }
  if (v == "+inf" || v == "+inff") {
    printPseudo("+inff", "+inf");
    return true;
  }
  if (v == "-inf" || v == "-inff") {
    printPseudo("-inff", "-inf");
    return true;
  }
  return false;
}

void Printer::printDecimal(const char *label, double value,
                           const char *suffix) {
  std::cout << label;
  std::cout << std::fixed << std::setprecision(1) << value;
  std::cout << suffix;
  std::cout.unsetf(std::ios_base::floatfield);
}

void Printer::printScalars(char c, double intSource, float f, double d) {
  unsigned char uc = static_cast<unsigned char>(c);

  if (uc > 127)
    std::cout << "char: impossible\n";
  else if (!std::isprint(uc))
    std::cout << "char: Non displayable\n";
  else
    std::cout << "char: '" << c << "'\n";

  if (intSource < static_cast<double>(INT_MIN) ||
      intSource > static_cast<double>(INT_MAX))
    std::cout << "int: impossible\n";
  else
    std::cout << "int: " << static_cast<int>(intSource) << "\n";
  printDecimal("float: ", static_cast<double>(f), "f\n");
  printDecimal("double: ", d, "");
  std::cout << std::endl;
}
