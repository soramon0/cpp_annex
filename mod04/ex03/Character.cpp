#include "Character.hpp"
#include <iostream>

Character::Character() : name("Character") {
  std::cout << "Character default constructor called" << std::endl;
  for (int i = 0; i < 4; i++) {
    this->inventory[i] = NULL;
  }
}

Character::Character(std::string const &name) : name(name) {
  std::cout << "Character name paramater constructor called" << std::endl;
  for (int i = 0; i < 4; i++) {
    this->inventory[i] = NULL;
  }
}

Character::~Character() {
  std::cout << "Character default deconstructor called" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i])
      delete this->inventory[i];
  }
}

Character::Character(const Character &other) : name(other.name) {
  std::cout << "Character default copy constructor called" << std::endl;

  for (int i = 0; i < 4; i++) {
    this->inventory[i] = NULL;
  }

  for (int i = 0; i < 4; i++) {
    if (other.inventory[i]) {
      this->inventory[i] = other.inventory[i]->clone();
    }
  }
}

Character &Character::operator=(const Character &other) {
  std::cout << "Character copy assignment operator called" << std::endl;

  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      delete this->inventory[i];
      this->inventory[i] = NULL;
    }

    this->name = other.name;
    for (int i = 0; i < 4; i++) {
      if (other.inventory[i])
        this->inventory[i] = other.inventory[i]->clone();
    }
  }
  return *this;
}

std::string const &Character::getName() const { return this->name; }

void Character::equip(AMateria *m) {
  if (!m)
    return;

  for (int i = 0; i < 4; i++) {
    if (this->inventory[i] == NULL) {
      this->inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
    return;

  this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && this->inventory[idx]) {
    this->inventory[idx]->use(target);
  }
}
