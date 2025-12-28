#include "Ice.hpp"
#include "Debug.hpp"
#include <iostream>

const std::string Ice::ICE_MATERIA = "ice";

Ice::Ice() : AMateria(ICE_MATERIA) {
  DEBUG_PRINT("Ice default constructor called" << std::endl);
}

Ice::Ice(Ice const &other) : AMateria(other) {
  DEBUG_PRINT("Ice default copy constructor called" << std::endl);
}

Ice::~Ice() { DEBUG_PRINT("Ice default deconstructor called" << std::endl); }

Ice &Ice::operator=(Ice const &other) {
  DEBUG_PRINT("Ice copy assignment operator called" << std::endl);
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
