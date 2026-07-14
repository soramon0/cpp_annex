#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {
  _numbers.reserve(n);
}

Span::Span(const Span &other)
    : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
  }
  return *this;
}

Span::~Span(void) {}

void Span::addNumber(int number) {
  if (_numbers.size() >= _maxSize)
    throw FullException();
  _numbers.push_back(number);
}

std::pair<int, int> Span::minMaxNumbers(void) const {
  int minVal = _numbers[0];
  int maxVal = _numbers[0];
  for (size_t i = 1; i < _numbers.size(); ++i) {
    if (_numbers[i] < minVal)
      minVal = _numbers[i];
    if (_numbers[i] > maxVal)
      maxVal = _numbers[i];
  }
  return std::make_pair(minVal, maxVal);
}

unsigned int Span::shortestSpan(void) const {
  if (_numbers.size() < 2)
    throw NoSpanException();

  std::vector<int> sorted(_numbers);
  std::sort(sorted.begin(), sorted.end());

  unsigned int minSpan = std::numeric_limits<unsigned int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    unsigned int diff =
        static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
    if (diff < minSpan)
      minSpan = diff;
  }
  return minSpan;
}

unsigned int Span::longestSpan(void) const {
  if (_numbers.size() < 2)
    throw NoSpanException();

  std::pair<int, int> extremes = minMaxNumbers();
  return static_cast<unsigned int>(extremes.second - extremes.first);
}

const char *Span::FullException::what() const throw() {
  return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
  return "Not enough numbers to find a span";
}
