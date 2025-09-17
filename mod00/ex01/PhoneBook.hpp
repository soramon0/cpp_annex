#include "Contact.hpp"
#include <stddef.h>

#define MAX_CONTACT 8

class PhoneBook {
  size_t _contacts_len;
  Contact _contacts[MAX_CONTACT];

public:
  PhoneBook() : _contacts_len(0) {}

  void usage() const;
  void accept_command();
  bool contact_add();
  void contact_search();
};
