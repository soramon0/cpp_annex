#include "Weapon.hpp"

Weapon::Weapon() : type() {}
Weapon::Weapon(std::string t) : type(t) {}

const std::string &Weapon::getType() const { return type; }

void Weapon::setType(const std::string newType) { type = newType; };
