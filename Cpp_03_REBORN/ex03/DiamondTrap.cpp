#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap's default constructor called." << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
    std::cout << "Frag's HP: " << this->FragTrap::get_hitPoints() << std::endl;
    std::cout << "Scav's HP: " << this->ScavTrap::get_hitPoints() << std::endl;
    std::cout << "DiamondTrap's name constructor called." << std::endl;
};

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap's default destructor called." << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
    this->set_name(other.get_name());
    this->set_hitPoints(other.get_hitPoints());
    this->set_energyPoints(other.get_energyPoints());
    this->set_attackDamage(other.get_attackDamage());
    std::cout << "DiamondTrap's copy constructor called." << std::endl;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "DiamondTrap's assignment operator (operator=) called." << std::endl;
    return (*this);
};

void DiamondTrap::whoAmI() {
    std::cout << "my name: " << this->_name << std::endl;
    std::cout << "daddy's name: " << this->ClapTrap::_name << std::endl;
};
