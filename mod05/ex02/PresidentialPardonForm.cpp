#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("Presidential Pardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
  AForm::operator=(other);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const {
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
