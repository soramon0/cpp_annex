#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
  this->type = "WrongCat";
  this->sound = "meow";
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  return *this;
}
