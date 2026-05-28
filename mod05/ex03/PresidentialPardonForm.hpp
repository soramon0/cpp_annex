#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(PresidentialPardonForm const &other);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
  virtual ~PresidentialPardonForm();

private:
  virtual void executeAction() const;
};
