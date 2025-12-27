#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  {
    std::cout << "Heap test" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;
  }
  std::cout << "-------" << std::endl;
  {
    std::cout << "Stack test" << std::endl;
    const Animal meta = Animal();
    const Animal j = Dog();
    const Animal i = Cat();

    std::cout << meta.getType() << " " << std::endl;
    std::cout << i.getType() << " " << std::endl;
    std::cout << j.getType() << " " << std::endl;
    j.makeSound();
    i.makeSound();
    meta.makeSound();
  }
  std::cout << "-------" << std::endl;
  {
    std::cout << "Stack ref test" << std::endl;
    const Animal &meta = Animal();
    const Animal &j = Dog();
    const Animal &i = Cat();

    std::cout << meta.getType() << " " << std::endl;
    std::cout << i.getType() << " " << std::endl;
    std::cout << j.getType() << " " << std::endl;
    j.makeSound();
    i.makeSound();
    meta.makeSound();
  }
  std::cout << "-------" << std::endl;
  {
    std::cout << "Wrong animal test" << std::endl;
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete i;
    delete meta;
  }
  return 0;
}
