#pragma once
#include <cmath>
#include <iostream>

class Fixed {
private:
  int _value;
  static const int _fractions = 8;

public:
  Fixed();
  Fixed(const int val);
  Fixed(const float val);
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
