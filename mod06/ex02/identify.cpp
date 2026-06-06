#include "identify.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
  switch (std::rand() % 3) {
  case 0:
    return new A();
  case 1:
    return new B();
  default:
    return new C();
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  } catch (...) {
    try {
      (void)dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
    } catch (...) {
      std::cout << "C" << std::endl;
    }
  }
}
