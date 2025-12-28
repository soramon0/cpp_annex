#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource() {
  std::cout << "MateriaSource default constructor called" << std::endl;

  for (int i = 0; i < INVENTORY_SIZE; i++) {
    this->inventory[i] = NULL;
  }
}

MateriaSource::MateriaSource(MateriaSource const &other) : IMateriaSource() {
  std::cout << "MateriaSource default copy constructor called" << std::endl;

  for (int i = 0; i < INVENTORY_SIZE; i++) {
    this->inventory[i] = NULL;

    if (other.inventory[i]) {
      this->inventory[i] = other.inventory[i]->clone();
    }
  }
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource default deconstructor called" << std::endl;

  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (this->inventory[i])
      delete this->inventory[i];
  }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  std::cout << "MateriaSource copy assignment operator called" << std::endl;

  if (this != &other) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
      delete this->inventory[i];
      this->inventory[i] = NULL;

      if (other.inventory[i]) {
        this->inventory[i] = other.inventory[i]->clone();
      }
    }
  }

  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (!m)
    return;

  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (this->inventory[i] == NULL) {
      this->inventory[i] = m->clone();
      delete m;
      return;
    }
  }
  delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (this->inventory[i] && this->inventory[i]->getType() == type) {
      return this->inventory[i]->clone();
    }
  }

  return NULL;
}
