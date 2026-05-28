#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

void AForm::checkGrade(u16 g) const {
  if (g < GRADE_HIGHEST)
    throw GradeTooHighException();
  if (g > GRADE_LOWEST)
    throw GradeTooLowException();
}

AForm::AForm()
    : name(""), isSigned(false), gradeToSign(GRADE_LOWEST),
      gradeToExecute(GRADE_LOWEST), target("") {}

AForm::AForm(std::string const &name, u16 gradeToSign, u16 gradeToExecute,
             std::string const &target)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute), target(target) {
  checkGrade(gradeToSign);
  checkGrade(gradeToExecute);
}

AForm::AForm(AForm const &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute),
      target(other.target) {}

AForm &AForm::operator=(AForm const &other) {
  if (this != &other)
    isSigned = other.isSigned;
  return *this;
}

AForm::~AForm() {}

std::string const &AForm::getTarget() const { return target; }

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

u16 AForm::getGradeToSign() const { return gradeToSign; }

u16 AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign)
    throw GradeTooLowException();
  isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!isSigned)
    throw NotSignedException();
  if (executor.getGrade() > gradeToExecute)
    throw GradeTooLowException();
  executeAction();
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
  os << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
     << ", grade to sign: " << form.getGradeToSign()
     << ", grade to execute: " << form.getGradeToExecute()
     << ", target: " << form.getTarget();
  return os;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Form grade is too low!";
}

const char *AForm::NotSignedException::what() const throw() {
  return "Form is not signed!";
}
