#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(const int &value) {
  std::cout << value << " ";
}

void incrementInt(int &value) {
  value++;
}

void printString(const std::string &value) {
  std::cout << value << std::endl;
}

template <typename T>
void printValue(const T &value) {
  std::cout << value << " ";
}

int main(void) {
  int numbers[] = {1, 2, 3, 4, 5};
  std::cout << "numbers: ";
  ::iter(numbers, 5, printInt);
  std::cout << std::endl;

  ::iter(numbers, 5, incrementInt);
  std::cout << "after increment: ";
  ::iter(numbers, 5, printInt);
  std::cout << std::endl;

  const int constants[] = {10, 20, 30};
  std::cout << "constants: ";
  ::iter(constants, 3, printInt);
  std::cout << std::endl;

  std::string words[] = {"hello", "world", "42"};
  ::iter(words, 3, printString);

  ::iter(numbers, 5, printValue<int>);
  std::cout << std::endl;

  return 0;
}
