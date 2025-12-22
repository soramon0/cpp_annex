#include "FragTrap.hpp"
#include <iostream>

int main() {
  ClapTrap clappy("sora");
  std::cout << clappy << std::endl;
  clappy.attack("Hero");
  
  FragTrap frag("FragBot");
  std::cout << frag << std::endl;
  frag.attack("Target");
  frag.highFivesGuys();
  std::cout << frag << std::endl;
  
  {
    FragTrap test("TestFrag");
  }
  
  return 0;
}
