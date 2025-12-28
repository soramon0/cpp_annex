#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
protected:
  const static int INVENTORY_SIZE = 4;
  AMateria *inventory[INVENTORY_SIZE];

public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  virtual ~MateriaSource();
  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);
};
