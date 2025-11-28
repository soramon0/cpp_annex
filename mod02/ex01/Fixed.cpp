#include "./Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &other) { this->_value = other._value; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->_value = other.getRawBits();
  }

  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }
