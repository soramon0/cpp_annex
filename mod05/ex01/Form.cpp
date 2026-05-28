#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

static void checkGrade(u16 g) {
  if (g < GRADE_HIGHEST)
    throw Form::GradeTooHighException();
  if (g > GRADE_LOWEST)
    throw Form::GradeTooLowException();
}

Form::Form()
    : name(""), isSigned(false), gradeToSign(GRADE_LOWEST),
      gradeToExecute(GRADE_LOWEST) {};

Form::Form(std::string const &name, u16 gradeToSign, u16 gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  checkGrade(this->gradeToSign);
  checkGrade(this->gradeToExecute);
};

Form::Form(Form const &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {};

Form &Form::operator=(Form const &other) {
  if (this != &other)
    isSigned = other.isSigned;
  return *this;
}

Form::~Form() {};

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign)
    throw GradeTooLowException();
  isSigned = true;
}

const std::string &Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

u16 Form::getGradeToSign() const { return gradeToSign; }

u16 Form::getGradeToExecute() const { return gradeToExecute; }

std::ostream &operator<<(std::ostream &os, Form const &form) {
  os << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
     << ", grade to sign: " << form.getGradeToSign()
     << ", grade to execute: " << form.getGradeToExecute();
  return os;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form grade is too low!";
}