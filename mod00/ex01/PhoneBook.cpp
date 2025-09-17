#include "PhoneBook.hpp"
#include <iostream>

void PhoneBook::usage() const {
  std::cout << "Enter phone book command: (ADD, SEARCH, EXIT)" << std::endl;
}

void PhoneBook::accept_command() {
  std::string command;

  while (true) {
    std::cin >> command;

    if (std::cin.fail() || command == "EXIT") {
      break;
    } else if (command == "ADD") {
      if (!contact_add())
        break;
    } else if (command == "SEARCH") {
      contact_search();
    }
    usage();
  }
}

bool ask_user(std::string label, std::string &field) {
  std::cout << "Enter " << label << ": ";

  field = "";
  while (field == "") {
    std::cin >> field;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << std::endl;
      return false;
    }
    if (field == "") {
      std::cerr << label << " cannot be empty" << std::endl;
      std::cin.clear();
    }
  }

  return true;
}

bool PhoneBook::contact_add() {
  size_t index = _contacts_len;
  if (_contacts_len == MAX_CONTACT) {
    index = 0;
  }
  Contact &contact = _contacts[index];
  contact.index = index + 1;

  if (!ask_user("first name", contact.fname)) {
    return false;
  }
  if (!ask_user("last name", contact.lname)) {
    return false;
  }
  if (!ask_user("nickname", contact.nickname)) {
    return false;
  }
  if (!ask_user("phone number", contact.phone)) {
    return false;
  }
  if (!ask_user("darkest secret", contact.darkest_secret)) {
    return false;
  }

  if (_contacts_len < MAX_CONTACT) {
    _contacts_len++;
  }
  return true;
}

void PhoneBook::contact_search() {
  for (size_t i = 0; i < _contacts_len; ++i) {
    _contacts[i].print();
  }
}
