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

    Character *sam = new Character("sam");
    AMateria *dropped = tmp;
    me->use(0, *sam);
    me->unequip(0);

    delete dropped;
    delete me;
    delete sam;
    delete src;
  }
  {
    std::cout << "--- Character deep copy test ---" << std::endl;
    Character *alice = new Character("Alice");
    alice->equip(new Ice());
    ICharacter *sam = new Character(*alice);
    delete alice;
    sam->use(0, *sam);
    delete sam;
  }
  {
    std::cout << "--- Check maximum un/equipment test ---" << std::endl;
    AMateria *cure = new Cure();
    AMateria *ice = new Ice();
    Character *me = new Character("me");
    me->equip(cure->clone());
    me->equip(cure->clone());
    me->equip(cure);
    me->equip(ice);
    me->equip(ice);
    me->unequip(2);
    me->unequip(2);
    me->unequip(6);
    delete me;
    delete cure;
  }
  return 0;
}
