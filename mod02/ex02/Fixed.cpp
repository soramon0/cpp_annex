#include "./Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int val) { this->_value = val * (1 << Fixed::_fractions); }

Fixed::Fixed(const float val) {
  this->_value = roundf(val * float(1 << Fixed::_fractions));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->_value = other.getRawBits();
  }

  return *this;
}

Fixed &Fixed::operator++() {
  this->_value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  this->_value++;
  return tmp;
}

Fixed &Fixed::operator--() {
  this->_value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  this->_value--;
  return tmp;
}

bool Fixed::operator==(const Fixed &other) const {
  if (this == &other)
    return true;
  return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return !(operator==(other));
}

bool Fixed::operator>(const Fixed &other) const {
  if (this == &other)
    return true;
  return this->_value > other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
  if (this == &other)
    return true;
  return this->_value >= other._value;
}

bool Fixed::operator<(const Fixed &other) const {
  if (this == &other)
    return true;
  return this->_value < other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
  if (this == &other)
    return true;
  return this->_value <= other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

int Fixed::toInt(void) const { return this->_value / (1 << Fixed::_fractions); }

float Fixed::toFloat(void) const {
  return this->_value / float(1 << Fixed::_fractions);
}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a < b)
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a < b)
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a > b)
    return a;
  return b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  return os << obj.toFloat();
}
