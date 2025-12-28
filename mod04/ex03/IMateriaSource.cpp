#include "IMateriaSource.hpp"
#include "Debug.hpp"
#include <iostream>

IMateriaSource::IMateriaSource() {
  DEBUG_PRINT("IMateriaSource default constructor called" << std::endl);
}

IMateriaSource::IMateriaSource(IMateriaSource const &other) {
  DEBUG_PRINT("IMateriaSource default copy constructor called" << std::endl);
  (void)other;
}

IMateriaSource::~IMateriaSource() {
  DEBUG_PRINT("IMateriaSource default deconstructor called" << std::endl);
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other) {
  DEBUG_PRINT("IMateriaSource copy assignment operator called" << std::endl);
  (void)other;
  return *this;
}
