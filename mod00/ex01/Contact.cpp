#include "Contact.hpp"
#include <iostream>

const std::string Contact::getFname() const { return _fname; }

const std::string Contact::getLname() const { return _lname; }

const std::string Contact::getNickname() const { return _nickname; }

const std::string Contact::getPhone() const { return _phone; }

const std::string Contact::getDarkestSecret() const { return _darkestSecret; }

void Contact::setFname(const std::string fname) { _fname = fname; }

void Contact::setLname(const std::string lname) { _lname = lname; }

void Contact::setNickname(const std::string nickname) { _nickname = nickname; }

void Contact::setPhone(const std::string phone) { _phone = phone; }

void Contact::setDarkestSecret(const std::string dk) { _darkestSecret = dk; }

void Contact::print() const {
  std::cout << "First Name: " << _fname << std::endl;
  std::cout << "Last Name: " << _lname << std::endl;
  std::cout << "Nickname: " << _nickname << std::endl;
  std::cout << "Phone Number: " << _phone << std::endl;
  std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
