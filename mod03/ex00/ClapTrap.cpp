#include "./ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n)
    : name(n), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "Default constructor for name called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
  }
  return *this;
}

std::string ClapTrap::toString() const {
  std::string prefix = "ClapTrap " + name + "(HP: ";
  std::ostringstream oss;

  oss << prefix << hitPoints << ", EP: " << energyPoints
      << ", AD: " << attackDamage << ")";
  return oss.str();
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &obj) {
  return os << obj.toString();
}

void ClapTrap::attack(const std::string &target) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " cannot attacks. No hit points left!"
              << std::endl;
    return;
  }

  if (energyPoints <= 0) {
    std::cout << "ClapTrap " << name
              << " cannot attacks. No energy points left!" << std::endl;
    return;
  }

  energyPoints--;
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " has already been destroyed!"
              << std::endl;
    return;
  }

  hitPoints -= amount;
  if (hitPoints <= 0) {
    hitPoints = 0;
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
  } else {
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " cannot repair: Already destroyed!"
              << std::endl;
    return;
  }

  if (energyPoints <= 0) {
    std::cout << " ClapTrap " << name
              << " cannot repair: No energy points left!" << std::endl;
    return;
  }

  energyPoints--;
  if (energyPoints < 0)
    energyPoints = 0;
  hitPoints += amount;
  std::cout << "ClapTrap " << name << " repairs itself for " << amount
            << " hit points!" << std::endl;
}
