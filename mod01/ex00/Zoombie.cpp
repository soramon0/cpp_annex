#include "Zoombie.hpp"
#include <iostream>

Zoombie::Zoombie(std::string name) : _name(name) {}

Zoombie::~Zoombie() { std::cout << _name << ": Destroyed..." << std::endl; }

void Zoombie::announce() const {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
