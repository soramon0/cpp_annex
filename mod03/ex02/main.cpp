#include "FragTrap.hpp"
#include <iostream>

int main() {
  std::cout << "---------" << std::endl;
  ClapTrap clappy("sora");
  std::cout << clappy << std::endl;
  clappy.attack("Hero");
  std::cout << "---------" << std::endl;

  std::cout << "---------" << std::endl;
  FragTrap frag("FragBot");
  std::cout << frag << std::endl;
  frag.attack("Target");
  frag.highFivesGuys();
  std::cout << frag << std::endl;
  std::cout << "---------" << std::endl;

  {
    std::cout << "---------" << std::endl;
    FragTrap test("TestFrag");
    std::cout << test << std::endl;
  }
  std::cout << "---------" << std::endl;
  return 0;
}
