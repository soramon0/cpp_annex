#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
  {
    std::cout << "--- Cannot init Animal ---" << std::endl;
    Dog doggy;
    Cat kitten;
    Animal *chien = new Dog();
    // Animal animal;  // This would fail to compile - Animal is abstract
    // Animal *animal = new Animal();  // This would also fail
    doggy.makeSound();
    kitten.makeSound();
    chien->makeSound();
    std::cout << chien->getType() << std::endl;
    delete chien;
  }
  return 0;
}
