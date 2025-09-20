#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name() {}
Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() { std::cout << _name << ": Destroyed..." << std::endl; }

void Zombie::setName(std::string name) { _name = name; }

void Zombie::announce() const {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
