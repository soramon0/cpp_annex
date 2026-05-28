#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &other);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
  virtual ~ShrubberyCreationForm();

private:
  virtual void executeAction() const;
};
