#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array {
private:
  T *_elements;
  unsigned int _size;

public:
  Array(void);
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  ~Array(void);

  unsigned int size(void) const;
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
};

template <typename T>
Array<T>::Array(void) : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other)
    : _elements(new T[other._size]), _size(other._size) {
  for (unsigned int i = 0; i < _size; i++)
    _elements[i] = other._elements[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    delete[] _elements;
    _size = other._size;
    _elements = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
      _elements[i] = other._elements[i];
  }
  return *this;
}

template <typename T>
Array<T>::~Array(void) {
  delete[] _elements;
}

template <typename T>
unsigned int Array<T>::size(void) const {
  return _size;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
  if (index >= _size)
    throw std::exception();
  return _elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
  if (index >= _size)
    throw std::exception();
  return _elements[index];
}
