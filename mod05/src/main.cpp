#include "Bureaucrat.hpp"
#include <iostream>

void testValidBureaucrat() {
  std::cout << "\n--- Test 1: Valid Bureaucrat ---" << std::endl;
  try {
    Bureaucrat bob("Bob", 75);
    // Print immediately to see initial state
    std::cout << "Before: " << bob << std::endl;

    bob.incrementGrade();
    std::cout << "After increment: " << bob << std::endl;

    bob.decrementGrade();
    std::cout << "After decrement: " << bob << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Unexpected Error: " << e.what() << std::endl;
  }
}

void testGradeTooHighConstructor() {
  std::cout << "\n--- Test 2: Constructor Grade Too High ---" << std::endl;
  try {
    std::cout << "Attempting to create Bureaucrat 'Zeus' with grade 0..."
              << std::endl;
    Bureaucrat god("Zeus", 0);
    // This line should never print if the logic is correct
    std::cout << "FAIL: Created " << god << std::endl;
  } catch (std::exception &e) {
    std::cout << "Success! Caught expected exception: " << e.what()
              << std::endl;
  }
}

void testGradeTooLowConstructor() {
  std::cout << "\n--- Test 3: Constructor Grade Too Low ---" << std::endl;
  try {
    std::cout << "Attempting to create Bureaucrat 'Peasant' with grade 151..."
              << std::endl;
    Bureaucrat peasant("Peasant", 151);
    // This line should never print if the logic is correct
    std::cout << "FAIL: Created " << peasant << std::endl;
  } catch (std::exception &e) {
    std::cout << "Success! Caught expected exception: " << e.what()
              << std::endl;
  }
}

void testIncrementLimit() {
  std::cout << "\n--- Test 4: Increment Limit (Grade 1 -> Error) ---"
            << std::endl;
  try {
    Bureaucrat boss("Boss", 1);
    std::cout << "Current State: " << boss << std::endl;

    std::cout << "Attempting to increment grade..." << std::endl;
    boss.incrementGrade(); // Should throw here

    std::cout << "FAIL: Grade changed to " << boss << std::endl;
  } catch (std::exception &e) {
    std::cout << "Success! Caught expected exception: " << e.what()
              << std::endl;
  }
}

void testDecrementLimit() {
  std::cout << "\n--- Test 5: Decrement Limit (Grade 150 -> Error) ---"
            << std::endl;
  try {
    Bureaucrat intern("Intern", 150);
    std::cout << "Current State: " << intern << std::endl;

    std::cout << "Attempting to decrement grade..." << std::endl;
    intern.decrementGrade(); // Should throw here

    std::cout << "FAIL: Grade changed to " << intern << std::endl;
  } catch (std::exception &e) {
    std::cout << "Success! Caught expected exception: " << e.what()
              << std::endl;
  }
}

int main() {
  testValidBureaucrat();
  testGradeTooHighConstructor();
  testGradeTooLowConstructor();
  testIncrementLimit();
  testDecrementLimit();

  return 0;
}
