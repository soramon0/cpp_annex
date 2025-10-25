#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
  complaintFunctions[0] = &Harl::debug;
  complaintFunctions[1] = &Harl::info;
  complaintFunctions[2] = &Harl::warning;
  complaintFunctions[3] = &Harl::error;

  levels[0] = "DEBUG";
  levels[1] = "INFO";
  levels[2] = "WARNING";
  levels[3] = "ERROR";
}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
  std::cout << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn't put "
         "enough bacon in my burger! If you did, I wouldn't be asking for more!"
      << std::endl;
  std::cout << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I've been "
         "coming for years, whereas you started working here just last month."
      << std::endl;
  std::cout << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
  std::cout << std::endl;
}

void Harl::complain(std::string level) {
  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      complaintFunction fn = complaintFunctions[i];
      (this->*fn)();
      return;
    }
  }
  std::cout << "[ Probably complaining about insignificant problems ]"
            << std::endl;
  std::cout << std::endl;
}
