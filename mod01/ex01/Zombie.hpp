#pragma once

#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();

  void announce(void) const;
  void setName(std::string);
};
