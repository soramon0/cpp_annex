#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat() : name(), grade(GRADE_LOWEST) {};

Bureaucrat::Bureaucrat(std::string n) : name(n), grade(GRADE_LOWEST) {};

Bureaucrat::Bureaucrat(std::string n, u16 g) : name(n) {
  if (g > GRADE_LOWEST) {
    throw GradeTooLowException();
  }

  if (g < GRADE_HIGHEST) {
    throw GradeTooHighException();
  }

  this->grade = g;
};

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade = other.grade;
  }
  return *this;
}

const std::string &Bureaucrat::getName() const { return name; }

u16 Bureaucrat::getGrade() const { return grade; }

std::string Bureaucrat::toString() const {
  std::ostringstream oss;
  std::string n = name;

  if (n.empty()) {
    n = "Bureaucrat";
  }

  oss << n << ", bureaucrat grade " << grade << ".";
  return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  return os << obj.toString();
}

void Bureaucrat::incrementGrade() {
  if (grade == GRADE_HIGHEST)
    throw GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade == GRADE_LOWEST)
    throw GradeTooLowException();
  grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}
