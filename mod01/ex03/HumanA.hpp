#pragma once

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
  std::string _name;
  Weapon _weapon;

public:
  HumanA(std::string, Weapon);
  void attack() const;
  void setWeapon(Weapon);
};
