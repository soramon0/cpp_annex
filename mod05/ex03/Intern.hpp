#pragma once

#include <string>

class AForm;

class Intern {
public:
  Intern();
  Intern(Intern const &other);
  Intern &operator=(Intern const &other);
  ~Intern();

  AForm *makeForm(std::string const &formName, std::string const &target);
};
