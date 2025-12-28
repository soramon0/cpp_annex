#include "AMateria.hpp"
#include "Debug.hpp"

AMateria::AMateria() : type("AMateria") {
  DEBUG_PRINT("AMateria default constructor called" << std::endl);
}

AMateria::AMateria(std::string const &type) : type(type) {
  DEBUG_PRINT("AMateria type paramater constructor called" << std::endl);
}

AMateria::AMateria(AMateria const &other) : type(other.type) {
  DEBUG_PRINT("AMateria default copy constructor called" << std::endl);
}

AMateria::~AMateria() {
  DEBUG_PRINT("AMateria default deconstructor called" << std::endl);
}

AMateria &AMateria::operator=(AMateria const &other) {
  DEBUG_PRINT("AMateria copy assignment operator called" << std::endl);
  (void)other;
  return *this;
}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target) { (void)target; }
