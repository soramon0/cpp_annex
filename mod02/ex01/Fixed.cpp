#include "./Fixed.hpp"

Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) {
  std::cout << "Int constructor called" << std::endl;
  this->_value = val * (1 << Fixed::_fractions);
}

Fixed::Fixed(const float val) {
  std::cout << "Float constructor called" << std::endl;
  this->_value = roundf(val * float(1 << Fixed::_fractions));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;

  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this != &other) {
    this->_value = other.getRawBits();
  }

  return *this;
}

int Fixed::toInt(void) const { return this->_value / (1 << Fixed::_fractions); }

float Fixed::toFloat(void) const {
  return this->_value / float(1 << Fixed::_fractions);
}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  return os << obj.toFloat();
}
