#pragma once
#include "./ClapTrap.hpp"
#include <string>
#include <sstream>


// const dest attack different messages;
class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string n);
  ~ScavTrap();

  void attack(const std::string &target);
  void guardGate();

  std::string toString() const;
};

std::ostream &operator<<(std::ostream &os, const ScavTrap &obj);
