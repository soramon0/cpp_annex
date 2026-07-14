#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main(void) {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  try {
    sp.addNumber(42);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  Span empty(5);
  try {
    empty.shortestSpan();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  Span big(20000);
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  std::vector<int> nums;
  nums.reserve(20000);
  for (int i = 0; i < 20000; ++i)
    nums.push_back(std::rand());
  big.addNumber(nums.begin(), nums.end());
  std::cout << "big shortest: " << big.shortestSpan() << std::endl;
  std::cout << "big longest: " << big.longestSpan() << std::endl;

  Span range(10);
  std::vector<int> batch;
  batch.push_back(100);
  batch.push_back(50);
  batch.push_back(75);
  range.addNumber(batch.begin(), batch.end());
  std::cout << "range shortest: " << range.shortestSpan() << std::endl;
  std::cout << "range longest: " << range.longestSpan() << std::endl;

  return 0;
}
