#pragma once

#include "common.hpp"
#include <exception>
#include <iosfwd>
#include <string>

class Bureaucrat;

class AForm {
private:
  std::string const name;
  bool isSigned;
  const u16 gradeToSign;
  const u16 gradeToExecute;
  std::string const target;

  void checkGrade(u16 g) const;

public:
  AForm();
  AForm(std::string const &name, u16 gradeToSign, u16 gradeToExecute,
        std::string const &target);
  AForm(AForm const &other);
  AForm &operator=(AForm const &other);
  virtual ~AForm();

  std::string const &getName() const;
  bool getIsSigned() const;
  u16 getGradeToSign() const;
  u16 getGradeToExecute() const;
  std::string const &getTarget() const;

  void beSigned(Bureaucrat const &bureaucrat);
  void execute(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };

  class NotSignedException : public std::exception {
    virtual const char *what() const throw();
  };

private:
  virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &form);
