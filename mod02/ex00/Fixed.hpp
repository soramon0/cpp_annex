#pragma once

class Fixed {
private:
  int _value;
  static const int _fractions = 8;

public:
  Fixed();
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};
