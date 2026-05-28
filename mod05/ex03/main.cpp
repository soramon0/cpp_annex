#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternPdfExample() {
  std::cout << "\n--- PDF example ---" << std::endl;
  Intern someRandomIntern;
  AForm *rrf;
  Bureaucrat b("Bureaucrat", 40);

  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  if (rrf) {
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
  }
}

void testInternAllForms() {
  std::cout << "\n--- Intern creates all forms ---" << std::endl;
  Intern intern;
  Bureaucrat bob("Bob", 40);
  const char *names[] = {"shrubbery creation", "robotomy request",
                         "presidential pardon", 0};
  const char *targets[] = {"home", "Bender", "Marvin", 0};

  for (int i = 0; names[i]; i++) {
    AForm *form = intern.makeForm(names[i], targets[i]);
    if (form) {
      std::cout << *form << std::endl;
      bob.signForm(*form);
      bob.executeForm(*form);
      delete form;
    }
  }
}

void testInternUnknownForm() {
  std::cout << "\n--- Unknown form name ---" << std::endl;
  Intern intern;
  AForm *form = intern.makeForm("coffee order", "desk");
  if (!form)
    std::cout << "No form created (NULL)" << std::endl;
  else
    delete form;
}

void testInternCopy() {
  std::cout << "\n--- Intern copy ---" << std::endl;
  Intern a;
  Intern b(a);
  Intern c;
  c = a;
  AForm *form = b.makeForm("presidential pardon", "Ford");
  if (form)
    delete form;
}

int main() {
  testInternPdfExample();
  testInternAllForms();
  testInternUnknownForm();
  testInternCopy();
  return 0;
}
