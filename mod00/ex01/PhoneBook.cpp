#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

void PhoneBook::usage() const {
  std::cout << "Enter a command: (ADD, SEARCH, EXIT)" << std::endl;
}

PhoneBook::PhoneBook() : _contactLen(0) {}

int PhoneBook::acceptCommand() {
  std::string command;

  while (true) {
    usage();

    std::cin >> std::ws;
    std::getline(std::cin, command);

    if (std::cin.fail())
      return -1;
    if (command == "EXIT" || std::cin.eof())
      return 0;
    if (command == "ADD") {
      if (!contactAdd())
        return -1;
    } else if (command == "SEARCH") {
      if (!contactSearch())
        return -1;
    }
  }
  return 0;
}

static bool collectContactInfo(Contact &contact) {
  const char *labels[5] = {"first name", "last name", "nickname",
                           "phone number", "darkest secret"};
  std::string input;

  for (int i = 0; i < 5; ++i) {
    std::cout << "Enter " << labels[i] << ": ";

    std::cin >> std::ws;
    std::getline(std::cin, input);

    if (std::cin.eof()) {
      std::cin.clear();
      std::cout << std::endl;
      return false;
    }

    if (input.empty()) {
      std::cout << labels[i] << " cannot be empty" << std::endl;
      return false;
    }

    switch (i) {
    case 0:
      contact.setFname(input);
      break;
    case 1:
      contact.setLname(input);
      break;
    case 2:
      contact.setNickname(input);
      break;
    case 3:
      contact.setPhone(input);
      break;
    case 4:
      contact.setDarkestSecret(input);
      break;
    }
  }

  return true;
}

bool PhoneBook::contactAdd() {
  size_t index = _contactLen;
  if (index == MAX_CONTACT)
    index = 0;
  Contact &contact = _contacts[index];

  if (!collectContactInfo(contact)) {
    return false;
  }

  if (_contactLen < MAX_CONTACT) {
    _contactLen++;
  }
  return true;
}

bool PhoneBook::contactSearch() const {
  if (_contactLen == 0) {
    std::cout << "No contacts to display." << std::endl;
    return true;
  }

  displayTablePreview();

  int index;
  std::cout << "Enter the index of the contact to display: ";
  std::cin >> index;
  if (std::cin.fail()) {
    if (std::cin.eof()) {
      std::cin.clear();
      std::cout << std::endl;
      return false;
    }
    std::cin.clear();
    std::cout << "Invalid input. Please enter a valid number." << std::endl;
    return false;
  }

  if (index < 0 || (size_t)index >= _contactLen) {
    std::cout << "Invalid index. Please enter a number between 0 and "
              << _contactLen - 1 << "." << std::endl;
    return true;
  }
  _contacts[index].print();
  return true;
}

static void display_field(const std::string &field) {
  std::string display_str = field;

  if (field.length() > COL_WIDTH) {
    display_str = field.substr(0, COL_WIDTH - 1) + ".";
  }

  std::cout << std::right << std::setw(COL_WIDTH) << display_str;
}

void PhoneBook::displayTablePreview() const {
  std::cout << std::right << "|" << std::setw(COL_WIDTH) << "Index"
            << "|" << std::setw(COL_WIDTH) << "First Name"
            << "|" << std::setw(COL_WIDTH) << "Last Name"
            << "|" << std::setw(COL_WIDTH) << "Nickname"
            << "|" << std::endl;

  for (size_t i = 0; i < _contactLen; ++i) {
    std::cout << std::right << "|" << std::setw(COL_WIDTH) << i;
    std::cout << "|";
    display_field(_contacts[i].getFname());
    std::cout << "|";
    display_field(_contacts[i].getLname());
    std::cout << "|";
    display_field(_contacts[i].getNickname());
    std::cout << "|" << std::endl;
  }
}
