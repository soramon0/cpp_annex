#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource() {
  std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &other) {
  std::cout << "IMateriaSource default copy constructor called" << std::endl;
  (void)other;
}

IMateriaSource::~IMateriaSource() {
  std::cout << "IMateriaSource default deconstructor called" << std::endl;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other) {
  std::cout << "IMateriaSource copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}
