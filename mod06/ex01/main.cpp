#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;
  data.value = 42;

  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);

  if (ptr == &data)
    std::cout << "Pointers match." << std::endl;
  else
    std::cout << "Pointers do not match." << std::endl;

  return 0;
}
