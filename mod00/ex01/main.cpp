#include "PhoneBook.hpp"
#include <iostream>

int main() {
  PhoneBook phoneBook;

  std::cout << phoneBook.contacts_saved() << std::endl;
  return 0;
}
