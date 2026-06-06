#include "Parser.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>

Parser::Parser() {}

Parser::Parser(const Parser &other) { (void)other; }

Parser &Parser::operator=(const Parser &other) {
  (void)other;
  return *this;
}

Parser::~Parser() {}

bool Parser::isFloatingBody(const std::string &s) {
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

bool Parser::isChar(const std::string &s) {
  return s.size() == 3 && s[0] == '\'' && s[2] == '\'';
}

bool Parser::parseChar(const std::string &s, char &out) {
  if (!isChar(s))
    return false;
  out = s[1];
  return true;
}

bool Parser::isInt(const std::string &s) {
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

bool Parser::isFloat(const std::string &s) {
  if (s.size() < 2 || s[s.size() - 1] != 'f')
    return false;
  return isFloatingBody(s.substr(0, s.size() - 1));
}

bool Parser::isDouble(const std::string &s) {
  if (s.empty() || s[s.size() - 1] == 'f')
    return false;
  if (s.find('.') == std::string::npos)
    return false;
  return isFloatingBody(s);
}

bool Parser::consumedAll(const char *start, char *end) {
  return end != start && *end == '\0';
}

bool Parser::parseInt(const std::string &s, int &out) {
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

bool Parser::parseFloat(const std::string &s, float &out) {
  std::string num = s.substr(0, s.size() - 1);
  char *end = NULL;
  errno = 0;
  float v = std::strtof(num.c_str(), &end);
  if (errno == ERANGE || !consumedAll(num.c_str(), end))
    return false;
  out = v;
  return true;
}

bool Parser::parseDouble(const std::string &s, double &out) {
  char *end = NULL;
  errno = 0;
  double v = std::strtod(s.c_str(), &end);
  if (errno == ERANGE || !consumedAll(s.c_str(), end))
    return false;
  out = v;
  return true;
}
