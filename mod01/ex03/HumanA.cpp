#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string n, Weapon w) : _name(n), _weapon(w) {};

void HumanA::attack() const {
  std::cout << _name << " attacks with their " << _weapon.getType()
            << std::endl;
}

void HumanA::setWeapon(Weapon w) { _weapon = w; };
