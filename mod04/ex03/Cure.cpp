#include "Cure.hpp"
#include "Debug.hpp"
#include <iostream>

const std::string Cure::CURE_MATERIA = "cure";

Cure::Cure() : AMateria(CURE_MATERIA) {
  DEBUG_PRINT("Cure default constructor called" << std::endl);
}

Cure::Cure(Cure const &other) : AMateria(other) {
  DEBUG_PRINT("Cure default copy constructor called" << std::endl);
}

Cure::~Cure() { DEBUG_PRINT("Cure default deconstructor called" << std::endl); }

Cure &Cure::operator=(Cure const &other) {
  DEBUG_PRINT("Cure copy assignment operator called" << std::endl);
  (void)other;
  return *this;
}

AMateria *Cure::clone() const {
  AMateria *materia = new Cure();
  return materia;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
