#include "Ice.hpp"
#include <iostream>

const std::string Ice::ICE_MATERIA = "ice";

Ice::Ice() : AMateria(ICE_MATERIA) {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other) {
  std::cout << "Ice default copy constructor called" << std::endl;
}

Ice::~Ice() { std::cout << "Ice default deconstructor called" << std::endl; }

Ice &Ice::operator=(Ice const &other) {
  std::cout << "Ice copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}

AMateria *Ice::clone() const {
  AMateria *materia = new Ice();
  return materia;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
