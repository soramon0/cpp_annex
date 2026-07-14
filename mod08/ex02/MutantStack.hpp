#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  MutantStack(void);
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);
  ~MutantStack(void);

  iterator begin(void);
  iterator end(void);
  const_iterator begin(void) const;
  const_iterator end(void) const;
  reverse_iterator rbegin(void);
  reverse_iterator rend(void);
  const_reverse_iterator rbegin(void) const;
  const_reverse_iterator rend(void) const;
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
    : std::stack<T, Container>(other) {}

template <typename T, typename Container>
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(const MutantStack &other) {
  if (this != &other)
    std::stack<T, Container>::operator=(other);
  return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin(void) {
  return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end(void) {
  return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin(void) const {
  return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end(void) const {
  return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin(void) {
  return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend(void) {
  return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin(void) const {
  return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend(void) const {
  return this->c.rend();
}
