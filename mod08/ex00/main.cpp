#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void) {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  try {
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << "Found in vector: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    easyfind(vec, 42);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);

  try {
    std::list<int>::iterator it = easyfind(lst, 20);
    std::cout << "Found in list: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    easyfind(lst, -1);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
