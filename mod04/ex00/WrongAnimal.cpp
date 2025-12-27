#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal"), sound("brrr") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
    : type(other.type), sound(other.sound) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type = other.type;
    this->sound = other.sound;
  }
  return *this;
}

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
  std::cout << type << " goes " << sound << std::endl;
}
