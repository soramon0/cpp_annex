#pragma once

#include "Contact.hpp"
#include <stddef.h>

#define MAX_CONTACT 4
#define COL_WIDTH 10

class PhoneBook {
  size_t _contactLen;
  Contact _contacts[MAX_CONTACT];

public:
  PhoneBook() : _contactLen(0) {}
  void acceptCommand();

private:
  bool contactAdd();
  bool contactSearch() const;
  void displayTablePreview() const;
  void usage() const;
};
