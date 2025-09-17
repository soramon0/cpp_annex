#include "Contact.hpp"
#include <iostream>

void Contact::print() const {
  std::cout << "First Name: " << fname << std::endl;
  std::cout << "Last Name: " << lname << std::endl;
  std::cout << "Nickname: " << nickname << std::endl;
  std::cout << "Phone Number: " << phone << std::endl;
  std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
