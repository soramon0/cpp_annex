#pragma once

#include <string>

struct Logger {
  enum Priority { DEBUG, INFO, WARNING, ERROR, UNKNOWN };
};

class Harl {
public:
  Harl();
  void complain(std::string level);
  Logger::Priority getPriority(const std::string lvl) const;

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  typedef void (Harl::*complaintFunction)(void);

  complaintFunction complaintFunctions[4];
  std::string levels[4];
};
