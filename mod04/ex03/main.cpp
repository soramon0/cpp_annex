#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
  {

    std::cout << "--- Simple materia test ---" << std::endl;
    AMateria *blue = new Ice();
    AMateria *green = blue->clone();

    std::cout << blue->getType() << std::endl;
    std::cout << green->getType() << std::endl;

    delete blue;
    delete green;
  }
  {
    std::cout << "--- Character test ---" << std::endl;

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria(Ice::ICE_MATERIA);
    me->equip(tmp);
    tmp = src->createMateria(Cure::CURE_MATERIA);
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
  }
  {
    std::cout << "--- Drop materia test ---" << std::endl;

    ICharacter *me = new Character("me");
    AMateria *tmp;

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    tmp = src->createMateria(Ice::ICE_MATERIA);
    me->equip(tmp);

    AMateria *dropped = tmp;
    me->unequip(0);

    delete dropped;
    delete me;
    delete src;
  }
  return 0;
}
