#pragma once
#include <string>

class WrongAnimal {
protected:
  std::string type;
  std::string sound;

public:
  WrongAnimal();
  ~WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);

  std::string getType() const;
  void makeSound() const;
};
