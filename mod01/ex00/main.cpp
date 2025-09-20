#include "Zoombie.hpp"

Zoombie *newZombie(std::string name);
void randomChump(std::string name);

int main() {
  Zoombie("Bob").announce();
  Zoombie helena = Zoombie("Helena");
  helena.announce();

  Zoombie *hippie = newZombie("Hippy");
  hippie->announce();
  delete hippie;

  randomChump("Jack");
  randomChump("Ryu");
  return 0;
}
