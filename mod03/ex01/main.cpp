#include "ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << "---------" << std::endl;
  ClapTrap clappy("sora");
  std::cout << clappy << std::endl;
  clappy.attack("Hero");
  std::cout << "---------" << std::endl;

  std::cout << "---------" << std::endl;
  ScavTrap scav("Roboto");
  std::cout << scav << std::endl;
  scav.attack("Enemy");
  scav.guardGate();
  std::cout << "---------" << std::endl;
  {
    std::cout << "---------" << std::endl;
    ScavTrap test("TestTrap");
    std::cout << test << std::endl;
  }

  return 0;
}
