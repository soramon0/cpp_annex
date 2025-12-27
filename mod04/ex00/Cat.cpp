#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
  this->type = "Cat";
  this->sound = "meow";
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat deconstructor called" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}
