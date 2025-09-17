#include <iostream>

class Contact {
  std::string _fname;
  std::string _lname;
  std::string _nickname;
  std::string _phone;
  std::string _darkest_secret;

public:
  Contact(): _fname(), _lname(), _nickname(), _phone(), _darkest_secret() {}
};
