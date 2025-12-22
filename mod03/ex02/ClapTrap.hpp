#pragma once
#include <iostream>
#include <sstream>
#include <string>

class ClapTrap {
protected:
  std::string name;
  int hitPoints;
  int energyPoints;
  int attackDamage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ~ClapTrap();
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string toString() const;
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &obj);
