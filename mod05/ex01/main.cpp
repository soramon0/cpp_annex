#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testValidBureaucrat() {
  std::cout << "\n--- Test: Valid Bureaucrat ---" << std::endl;
  try {
    Bureaucrat bob("Bob", 75);
    std::cout << "Before: " << bob << std::endl;
    bob.incrementGrade();
    std::cout << "After increment: " << bob << std::endl;
    bob.decrementGrade();
    std::cout << "After decrement: " << bob << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Unexpected: " << e.what() << std::endl;
  }
}

void testBureaucratGradeExceptions() {
  std::cout << "\n--- Test: Bureaucrat grade exceptions ---" << std::endl;
  try {
    Bureaucrat god("Zeus", 0);
    std::cout << "FAIL: " << god << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat peasant("Peasant", 151);
    std::cout << "FAIL: " << peasant << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }
}

void testFormGradeExceptions() {
  std::cout << "\n--- Test: Form grade exceptions ---" << std::endl;
  try {
    Form bad("bad", 0, 50);
    std::cout << "FAIL: " << bad << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }
  try {
    Form bad("bad", 50, 200);
    std::cout << "FAIL: " << bad << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }
}

void testFormSigning() {
  std::cout << "\n--- Test: Form signing ---" << std::endl;
  Bureaucrat chief("Chief", 5);
  Bureaucrat clerk("Clerk", 100);
  Form contract("28B", 50, 30);

  std::cout << contract << std::endl;

  chief.signForm(contract);
  std::cout << contract << std::endl;

  clerk.signForm(contract);
}

void testBeSignedDirectly() {
  std::cout << "\n--- Test: beSigned via try/catch ---" << std::endl;
  Bureaucrat weak("Weak", 80);
  Form f("permit", 40, 20);

  try {
    f.beSigned(weak);
    std::cout << "Signed: " << f << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }
}

void testFormCopyAssign() {
  std::cout << "\n--- Test: Form copy / assign ---" << std::endl;
  Form a("A", 10, 20);
  Form b(a);
  std::cout << "copy: " << b << std::endl;
  Form c("C", 30, 40);
  c = a;
  std::cout << "assign: " << c << std::endl;
}

int main() {
  testValidBureaucrat();
  testBureaucratGradeExceptions();
  testFormGradeExceptions();
  testFormSigning();
  testBeSignedDirectly();
  testFormCopyAssign();
  return 0;
}