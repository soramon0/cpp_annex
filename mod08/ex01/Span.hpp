#pragma once

#include <exception>
#include <iterator>
#include <utility>
#include <vector>

class Span {
private:
  unsigned int _maxSize;
  std::vector<int> _numbers;

  std::pair<int, int> minMaxNumbers(void) const;

public:
  Span(void);
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span(void);

  void addNumber(int number);
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;

  template <typename InputIterator>
  void addNumber(InputIterator begin, InputIterator end) {
    typename std::iterator_traits<InputIterator>::difference_type count =
        std::distance(begin, end);
    if (count < 0 ||
        static_cast<unsigned int>(count) > _maxSize - _numbers.size())
      throw FullException();
    _numbers.insert(_numbers.end(), begin, end);
  }

  class FullException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class NoSpanException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};
