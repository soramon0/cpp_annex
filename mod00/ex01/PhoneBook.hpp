#include "Contact.hpp"
#include <stddef.h>

#define MAX_CONTACT 4
#define COL_WIDTH 10

class PhoneBook {
  size_t _contactLen;
  Contact _contacts[MAX_CONTACT];

public:
  PhoneBook() : _contactLen(0) {}

  void usage() const;
  void acceptCommand();

private:
  bool contactAdd();
  void contactSearch() const;
  void displayTablePreview() const;
};
