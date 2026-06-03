#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>

static void printAllImpossible() {
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: impossible\n";
  std::cout << "double: impossible" << std::endl;
}

static void printPseudo(const char *floatLine, const char *doubleLine) {
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: " << floatLine << "\n";
  std::cout << "double: " << doubleLine << std::endl;
}

static void printSymbol(const Symbol::Kind symbol) {
  switch (symbol) {
  case Symbol::NAN:
  case Symbol::NANF:
    printPseudo("nanf", "nan");
    break;
  case Symbol::INF_PLUS:
  case Symbol::INFF_PLUS:
    printPseudo("+inff", "+inf");
    break;
  case Symbol::INF_MINUS:
  case Symbol::INFF_MINUS:
    printPseudo("-inff", "-inf");
    break;
  default:
    std::cerr << "should never get here." << std::endl;
  }
}

static bool isFloatingBody(const std::string &s) {
  if (s.empty())
    return false;

  size_t i = 0;
  if (s[i] == '+' || s[i] == '-')
    i++;
  if (i >= s.size())
    return false;

  bool hasDot = false;
  bool hasDigit = false;

  if (s[i] == '.') {
    hasDot = true;
    i++;
  }
  while (i < s.size()) {
    if (s[i] == '.') {
      if (hasDot)
        return false;
      hasDot = true;
      i++;
      continue;
    }
    if (!std::isdigit(s[i]))
      return false;
    hasDigit = true;
    i++;
  }
  return hasDigit;
}

static bool isIntLiteral(const std::string &s) {
  if (s.empty())
    return false;

  size_t i = 0;
  if (s[i] == '+' || s[i] == '-')
    i++;
  if (i >= s.size())
    return false;

  for (; i < s.size(); i++) {
    if (!std::isdigit(s[i]))
      return false;
  }
  return true;
}

static bool isFloatLiteral(const std::string &s) {
  if (s.size() < 2 || s[s.size() - 1] != 'f')
    return false;
  return isFloatingBody(s.substr(0, s.size() - 1));
}

static bool isDoubleLiteral(const std::string &s) {
  if (s.empty() || s[s.size() - 1] == 'f')
    return false;
  if (s.find('.') == std::string::npos)
    return false;
  return isFloatingBody(s);
}

static bool consumedAll(const char *start, char *end) {
  return end != start && *end == '\0';
}

static bool parseInt(const std::string &s, int &out) {
  char *end = NULL;
  errno = 0;
  long v = std::strtol(s.c_str(), &end, 10);
  if (errno == ERANGE || !consumedAll(s.c_str(), end))
    return false;
  if (v < INT_MIN || v > INT_MAX)
    return false;
  out = static_cast<int>(v);
  return true;
}

static bool parseFloat(const std::string &s, float &out) {
  std::string num = s.substr(0, s.size() - 1);
  char *end = NULL;
  errno = 0;
  float v = std::strtof(num.c_str(), &end);
  if (errno == ERANGE || !consumedAll(num.c_str(), end))
    return false;
  out = v;
  return true;
}

static bool parseDouble(const std::string &s, double &out) {
  char *end = NULL;
  errno = 0;
  double v = std::strtod(s.c_str(), &end);
  if (errno == ERANGE || !consumedAll(s.c_str(), end))
    return false;
  out = v;
  return true;
}

static bool isWholeNumber(double value) {
  return value == static_cast<int>(value);
}

static void printCharLine(char c) {
  unsigned char uc = static_cast<unsigned char>(c);

  if (uc > 127) {
    std::cout << "char: impossible\n";
    return;
  }
  if (!std::isprint(uc)) {
    std::cout << "char: Non displayable\n";
    return;
  }
  std::cout << "char: '" << c << "'\n";
}

static void printIntLine(double value) {
  if (value < static_cast<double>(INT_MIN) ||
      value > static_cast<double>(INT_MAX) || !isWholeNumber(value)) {
    std::cout << "int: impossible\n";
    return;
  }
  std::cout << "int: " << static_cast<int>(value) << "\n";
}

static void printFloatLine(float value) {
  std::cout << "float: ";
  if (isWholeNumber(static_cast<double>(value)))
    std::cout << std::fixed << std::setprecision(1) << value << "f\n";
  else
    std::cout << value << "f\n";
  std::cout.unsetf(std::ios_base::floatfield);
}

static void printDoubleLine(double value) {
  std::cout << "double: ";
  if (isWholeNumber(value))
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
  else
    std::cout << value << std::endl;
}

static void printScalars(char c, int i, float f, double d) {
  printCharLine(c);
  printIntLine(static_cast<double>(i));
  printFloatLine(f);
  printDoubleLine(d);
}

void ScalarConverter::convert(const std::string &val) {
  Symbol::Kind symbol = Symbol::getSymbol(val);

  if (symbol != Symbol::UNKNWON) {
    printSymbol(symbol);
    return;
  }

  if (isFloatLiteral(val)) {
    float f = 0.0f;
    if (parseFloat(val, f)) {
      printScalars(static_cast<char>(f), static_cast<int>(f), f,
                   static_cast<double>(f));
      return;
    }
  } else if (isDoubleLiteral(val)) {
    double d = 0.0;
    if (parseDouble(val, d)) {
      printScalars(static_cast<char>(d), static_cast<int>(d),
                   static_cast<float>(d), d);
      return;
    }
  } else if (isIntLiteral(val)) {
    int i = 0;
    if (parseInt(val, i)) {
      printScalars(static_cast<char>(i), i, static_cast<float>(i),
                   static_cast<double>(i));
      return;
    }
  }

  printAllImpossible();
}

Symbol::Kind Symbol::getSymbol(const std::string &v) {
  if (v == "nan")
    return Symbol::NAN;
  if (v == "nanf")
    return Symbol::NANF;
  if (v == "+inf")
    return Symbol::INF_PLUS;
  if (v == "-inf")
    return Symbol::INF_MINUS;
  if (v == "+inff")
    return Symbol::INFF_PLUS;
  if (v == "-inff")
    return Symbol::INFF_MINUS;
  return Symbol::UNKNWON;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}
