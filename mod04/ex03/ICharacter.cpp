#include "ICharacter.hpp"
#include "Debug.hpp"
#include <iostream>

ICharacter::ICharacter() {
  DEBUG_PRINT("ICharacter default constructor called" << std::endl);
}

ICharacter::ICharacter(ICharacter const &other) {
  DEBUG_PRINT("ICharacter default copy constructor called" << std::endl);
  (void)other;
}

ICharacter::~ICharacter() {
  DEBUG_PRINT("ICharacter default deconstructor called" << std::endl);
}

ICharacter &ICharacter::operator=(ICharacter const &other) {
  DEBUG_PRINT("ICharacter copy assignment operator called" << std::endl);
  (void)other;
  return *this;
}
