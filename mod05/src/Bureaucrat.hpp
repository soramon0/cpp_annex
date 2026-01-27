#pragma once

#include <exception>
#include <string>

typedef unsigned short u16;

#define GRADE_LOWEST 150
#define GRADE_HIGHEST 1

class Bureaucrat {
private:
  std::string const name;
  u16 grade;

public:
  Bureaucrat();
  ~Bureaucrat();
  Bureaucrat(std::string n);
  Bureaucrat(std::string n, u16 g);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  const std::string &getName() const;
  u16 getGrade() const;
  std::string toString() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
