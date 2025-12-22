#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap Default constructor called" << std::endl;
  this->name = "FragTrap";
  this->attackDamage = 30;
  this->energyPoints = 100;
  this->hitPoints = 100;
};

FragTrap::FragTrap(std::string n) : ClapTrap(n) {
  std::cout << "FragTrap Default constructor for name called" << std::endl;
  this->attackDamage = 30;
  this->energyPoints = 100;
  this->hitPoints = 100;
};

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
  if (hitPoints <= 0) {
    std::cout << "FragTrap " << name << " cannot attacks. No hit points left!"
              << std::endl;
    return;
  }

  if (energyPoints <= 0) {
    std::cout << "FragTrap " << name
              << " cannot attacks. No energy points left!" << std::endl;
    return;
  }

  energyPoints--;
  std::cout << "FragTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << " requests a positive high five!"
            << std::endl;
}

std::ostream &operator<<(std::ostream &os, const FragTrap &obj) {
  return os << obj.toString();
}
