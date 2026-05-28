#pragma once

#include "common.hpp"
#include <exception>
#include <iosfwd>
#include <string>

class Bureaucrat;

class Form {
private:
  std::string const name;
  bool isSigned;
  const u16 gradeToSign;
  const u16 gradeToExecute;

public:
  Form();
  Form(std::string const &name, u16 gradeToSign, u16 gradeToExecute);
  Form(Form const &other);
  Form &operator=(Form const &other);
  ~Form();

  std::string const &getName() const;
  bool getIsSigned() const;
  u16 getGradeToSign() const;
  u16 getGradeToExecute() const;

  void beSigned(Bureaucrat const &bureaucrat);

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Form const &form);