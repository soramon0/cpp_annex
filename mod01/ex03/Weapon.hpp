#pragma once

#include <string>

class Weapon {
private:
  std::string type;

public:
  Weapon();
  Weapon(std::string);
  const std::string &getType() const;
  void setType(const std::string);
};
