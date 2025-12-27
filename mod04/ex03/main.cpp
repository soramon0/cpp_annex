#include "Ice.hpp"
#include <iostream>

int main() {
  std::cout << "--- Program ---" << std::endl;
  AMateria *blue = new Ice();
  AMateria *green = blue->clone();

  std::cout << blue->getType() << std::endl;
  std::cout << green->getType() << std::endl;

  delete blue;
  delete green;
  return 0;
}
