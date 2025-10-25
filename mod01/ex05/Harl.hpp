#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  typedef void (Harl::*complaintFunction)(void);

  complaintFunction complaintFunctions[4];
  std::string levels[4];

public:
  Harl();
  void complain(std::string level);
};

#endif
