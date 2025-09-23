#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main() {
  int size = 10;
  Zombie *horde = zombieHorde(size, "Walker");

  if (!horde) return 1;

  for (int i = 0; i < size; ++i) {
    horde[i].announce();
  }

  delete[] horde;
  return 0;
}
