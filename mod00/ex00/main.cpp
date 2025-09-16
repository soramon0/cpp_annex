#include <cctype>
#include <iostream>

char *str_toupper(char *str) {
  for (int i = 0; str[i]; ++i) {
    str[i] = std::toupper(static_cast<unsigned char>(str[i]));
  }
  return str;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; ++i) {
    std::cout << str_toupper(argv[i]);
  }
  std::cout << std::endl;

  return 0;
}
