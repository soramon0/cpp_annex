#pragma once
#include "./ClapTrap.hpp"
#include <string>
#include <sstream>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string n);
  ~FragTrap();

  void attack(const std::string &target);
  void highFivesGuys(void);

  std::string toString() const;
};

std::ostream &operator<<(std::ostream &os, const FragTrap &obj);

