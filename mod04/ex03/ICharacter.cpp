#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter() {
  std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &other) {
  std::cout << "ICharacter default copy constructor called" << std::endl;
}

ICharacter::~ICharacter() {
  std::cout << "ICharacter default deconstructor called" << std::endl;
}

ICharacter &ICharacter::operator=(ICharacter const &other) {
  std::cout << "ICharacter copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}
