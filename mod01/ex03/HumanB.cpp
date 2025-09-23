#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : _name(n) {};

void HumanB::attack() const {
  std::cout << _name << " attacks with their " << _weapon.getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon w) { _weapon = w; };
