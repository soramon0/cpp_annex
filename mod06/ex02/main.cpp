#include "Base.hpp"
#include "identify.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(static_cast<unsigned>(std::time(NULL)));

  for (int i = 0; i < 10; i++) {
    Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;
  }

  return 0;
}
