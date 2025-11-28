#pragma once
#include <iostream>
#include <cmath>

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

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
