#pragma once

#include <string>

class Parser {
public:
  static bool isChar(const std::string &s);
  static bool isInt(const std::string &s);
  static bool isFloat(const std::string &s);
  static bool isDouble(const std::string &s);
  static bool parseChar(const std::string &s, char &out);
  static bool parseInt(const std::string &s, int &out);
  static bool parseFloat(const std::string &s, float &out);
  static bool parseDouble(const std::string &s, double &out);

private:
  Parser();
  Parser(const Parser &other);
  Parser &operator=(const Parser &other);
  ~Parser();

  static bool isFloatingBody(const std::string &s);
  static bool consumedAll(const char *start, char *end);
};
