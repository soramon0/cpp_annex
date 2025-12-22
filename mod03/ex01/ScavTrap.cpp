#include "./ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap Default constructor called" << std::endl;
  this->name = "ScavTrap";
  this->attackDamage = 20;
  this->energyPoints = 50;
  this->hitPoints = 100;
};

ScavTrap::ScavTrap(std::string n) : ClapTrap(n) {
  std::cout << "ScavTrap Default constructor for name called" << std::endl;
  this->attackDamage = 20;
  this->energyPoints = 50;
  this->hitPoints = 100;
};

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called" << std::endl; }

void ScavTrap::attack(const std::string &target) {
  if (hitPoints <= 0) {
    std::cout << "ScavTrap " << name << " cannot attacks. No hit points left!"
              << std::endl;
    return;
  }

  if (energyPoints <= 0) {
    std::cout << "ScavTrap " << name
              << " cannot attacks. No energy points left!" << std::endl;
    return;
  }

  energyPoints--;
  std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " is now in Gate keeper mode."
            << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ScavTrap &obj) {
return os << obj.toString();
}

std::string ScavTrap::toString() const {
  std::string prefix = "ScavTrap " + name + "(HP: ";
  std::ostringstream oss;

  oss << prefix << hitPoints << ", EP: " << energyPoints
      << ", AD: " << attackDamage << ")";
  return oss.str();
}
