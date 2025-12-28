#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
protected:
  std::string name;
  AMateria *inventory[4];

public:
  Character();
  Character(std::string const &name);
  Character(const Character &other);
  virtual ~Character();
  Character &operator=(const Character &other);

  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};
