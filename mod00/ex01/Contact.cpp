#include "Contact.hpp"
#include <iostream>

void Contact::print() const {
  std::cout << index << " " << fname << " " << lname << " " << nickname << " "
            << phone << " " << darkest_secret << std::endl;
}
