#include "ScavTrap.hpp"
#include <iostream>

int main() {
  ClapTrap clappy("sora");
  std::cout << clappy << std::endl;
  clappy.attack("Hero");
  
  ScavTrap scav("Roboto");
  std::cout << scav << std::endl;
  scav.attack("Enemy");
  scav.guardGate();
  std::cout << scav << std::endl;
  
  {
    ScavTrap test("TestBot");
  }
  
  return 0;
}
