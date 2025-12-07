#include "ClapTrap.hpp"
#include <iostream>

int main() {
  ClapTrap c;
  ClapTrap clappy("sora");
  std::cout << c << std::endl;
  std::cout << clappy << std::endl;

  clappy.attack("Hero");
  clappy.beRepaired(6);
  clappy.takeDamage(12);
  clappy.attack("Hero");

  std::cout << clappy << std::endl;
  return 0;
}
