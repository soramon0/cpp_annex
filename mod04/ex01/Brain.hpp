#pragma once
#include <string>

class Brain {
protected:
  std::string ideas[100];

public:
  Brain();
  ~Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
};
