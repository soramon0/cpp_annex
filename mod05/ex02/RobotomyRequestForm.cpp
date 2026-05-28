#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("Robotomy Request", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
  AForm::operator=(other);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
  std::cout << "* drilling noises *" << std::endl;
  std::srand(std::time(0));
  if (std::rand() % 2)
    std::cout << getTarget() << " has been robotomized successfully"
              << std::endl;
  else
    std::cout << "Robotomy of " << getTarget() << " failed" << std::endl;
}
