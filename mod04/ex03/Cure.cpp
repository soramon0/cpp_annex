#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
  std::cout << "Cure default copy constructor called" << std::endl;
}

Cure::~Cure() { std::cout << "Cure default deconstructor called" << std::endl; }

Cure &Cure::operator=(Cure const &other) {
  std::cout << "Cure copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}

AMateria *Cure::clone() const {
  AMateria *materia = new Cure();
  return materia;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *"
            << std::endl;
}
