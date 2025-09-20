#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main() {
  Zombie("Bob").announce();
  Zombie helena = Zombie("Helena");
  helena.announce();

  Zombie *hippie = newZombie("Hippy");
  hippie->announce();
  delete hippie;

  randomChump("Jack");
  randomChump("Ryu");
  return 0;
}
