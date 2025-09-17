#include <stddef.h>
#include <string>

class Contact {
public:
  std::string fname;
  std::string lname;
  std::string nickname;
  std::string phone;
  std::string darkest_secret;
  size_t index;

  Contact()
      : fname(), lname(), nickname(), phone(), darkest_secret(), index(0) {}
  Contact(size_t i)
      : fname(), lname(), nickname(), phone(), darkest_secret(), index(i) {}

  void print() const;
};
