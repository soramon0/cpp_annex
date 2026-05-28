#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void testBureaucratBasics() {
  std::cout << "\n--- Bureaucrat basics ---" << std::endl;
  try {
    Bureaucrat bob("Bob", 75);
    std::cout << bob << std::endl;
    bob.incrementGrade();
    std::cout << bob << std::endl;
    bob.decrementGrade();
    std::cout << bob << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Unexpected: " << e.what() << std::endl;
  }
}

void testFormSigning() {
  std::cout << "\n--- Form signing ---" << std::endl;
  Bureaucrat chief("Chief", 5);
  Bureaucrat clerk("Clerk", 100);
  ShrubberyCreationForm shrub("garden");

  std::cout << shrub << std::endl;
  chief.signForm(shrub);
  clerk.signForm(shrub);
}

void testExecuteUnsigned() {
  std::cout << "\n--- Execute unsigned form ---" << std::endl;
  Bureaucrat exec("Executor", 40);
  RobotomyRequestForm robo("Bender");
  exec.executeForm(robo);
}

void testExecuteLowGrade() {
  std::cout << "\n--- Execute with low grade ---" << std::endl;
  Bureaucrat weak("Weak", 50);
  PresidentialPardonForm pardon("Arthur");
  Bureaucrat strong("Strong", 3);
  strong.signForm(pardon);
  weak.executeForm(pardon);
}

void testShrubbery() {
  std::cout << "\n--- Shrubbery creation ---" << std::endl;
  Bureaucrat bob("Bob", 130);
  ShrubberyCreationForm form("home");
  bob.signForm(form);
  bob.executeForm(form);
}

void testRobotomy() {
  std::cout << "\n--- Robotomy ---" << std::endl;
  Bureaucrat b("Bender's friend", 40);
  RobotomyRequestForm form("Bender");
  b.signForm(form);
  b.executeForm(form);
  b.executeForm(form);
}

void testPresidentialPardon() {
  std::cout << "\n--- Presidential pardon ---" << std::endl;
  Bureaucrat zaphod("Zaphod", 1);
  PresidentialPardonForm form("Marvin");
  zaphod.signForm(form);
  zaphod.executeForm(form);
}

void testConcreteCopy() {
  std::cout << "\n--- Concrete form copy ---" << std::endl;
  ShrubberyCreationForm a("yard");
  ShrubberyCreationForm b(a);
  std::cout << b << std::endl;
}

int main() {
  testBureaucratBasics();
  testFormSigning();
  testExecuteUnsigned();
  testExecuteLowGrade();
  testShrubbery();
  testRobotomy();
  testPresidentialPardon();
  testConcreteCopy();
  return 0;
}
