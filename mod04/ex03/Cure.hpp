#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &other);
  virtual ~Cure();
  Cure &operator=(const Cure &other);

  static const std::string CURE_MATERIA;

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
