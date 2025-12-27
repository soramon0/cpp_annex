#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
  std::cout << "Dog default constructor called" << std::endl;
  this->type = "Dog";
  this->brain = new Brain();
}

Dog::~Dog() {
  std::cout << "Dog deconstructor called" << std::endl;
  delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog copy assignment operator called" << std::endl;

  if (this != &other) {
    Animal::operator=(other);
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
