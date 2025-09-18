#pragma once

#include <string>

class Contact {
public:
  std::string fname;
  std::string lname;
  std::string nickname;
  std::string phone;
  std::string darkestSecret;

  Contact() : fname(), lname(), nickname(), phone(), darkestSecret() {}

  void print() const;
};
