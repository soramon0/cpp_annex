#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
  {
    std::cout << "---6 animal test---" << std::endl;
    int len = 6;
    Animal *animals[len];
    for (int i = 0; i < len; i++) {
      if (i < len / 2)
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
    }

    int dogs = 0;
    int cats = 0;
    for (int i = 0; i < len; i++) {
      if (animals[i]->getType() == "Dog")
        dogs++;
      if (animals[i]->getType() == "Cat")
        cats++;
    }

    std::cout << animals[0]->getType() << "(" << dogs << ")" << std::endl;
    std::cout << animals[len - 1]->getType() << "(" << cats << ")" << std::endl;

    for (int i = 0; i < len; i++) {
      delete animals[i];
    }
  }
  {
    std::cout << "---Deep copy deletion test---" << std::endl;
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;
  }
  {
    std::cout << "--- Deep copy verification ---" << std::endl;
    Dog doggy;
    Cat kitten;
    {
      std::cout << "--- tmp ---" << std::endl;
      Dog tmp = doggy;
      Cat tmp2 = kitten;
    }
    doggy.makeSound();
    kitten.makeSound();
  }
  return 0;
}
