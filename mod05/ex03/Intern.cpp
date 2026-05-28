#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static AForm *createShrubbery(std::string const &target) {
  return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string const &target) {
  return new RobotomyRequestForm(target);
}

static AForm *createPresidential(std::string const &target) {
  return new PresidentialPardonForm(target);
}

struct FormEntry {
  const char *name;
  AForm *(*create)(std::string const &target);
};

static FormEntry const formRegistry[] = {
    {"shrubbery creation", &createShrubbery},
    {"robotomy request", &createRobotomy},
    {"presidential pardon", &createPresidential},
    {0, 0}};

Intern::Intern() {}

Intern::Intern(Intern const &other) { (void)other; }

Intern &Intern::operator=(Intern const &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  for (int i = 0; formRegistry[i].name; i++) {
    if (formName == formRegistry[i].name) {
      std::cout << "Intern creates " << formName << std::endl;
      return formRegistry[i].create(target);
    }
  }
  std::cout << "Error: unknown form name \"" << formName << "\"" << std::endl;
  return 0;
}
