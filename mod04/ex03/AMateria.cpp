#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("AMateria") {
  std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
  std::cout << "AMateria type paramater constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) : type(other.type) {
  std::cout << "AMateria default copy constructor called" << std::endl;
}

AMateria::~AMateria() {
  std::cout << "AMateria default deconstructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
  std::cout << "AMateria copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target) { (void)target; }
