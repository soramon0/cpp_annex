#include "Contact.hpp"
#include <stddef.h>

class PhoneBook {
  size_t _contacts_len;
  Contact _contacts[8];

public:
  PhoneBook() : _contacts_len(0), _contacts() {}
  size_t contacts_saved() const;
};
