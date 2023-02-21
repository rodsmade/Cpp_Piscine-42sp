#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    this->_name = "unnamed diamond trap";
    this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
    this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
    this->_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << LIGHT_RED "DiamondTrap" RESET "'s default constructor called." << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
    this->_name = name;
    ClapTrap::_name = name + "_clap_name";
    this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
    this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
    this->_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << LIGHT_RED "DiamondTrap" RESET "'s name constructor called." << std::endl;
};

DiamondTrap::~DiamondTrap() {
    std::cout << LIGHT_RED "DiamondTrap" RESET "'s default destructor called." << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other)  : ScavTrap(other), FragTrap(other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_RED "DiamondTrap" RESET "'s copy constructor called." << std::endl;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_RED "DiamondTrap" RESET "'s assignment operator (operator=) called." << std::endl;
    return (*this);
};

void DiamondTrap::whoAmI() {
    std::cout << "My name is " BOLD ORANGE << this->_name << RESET " and my daddy's name is " BOLD VIOLET << this->ClapTrap::_name << RESET << std::endl;
};

void DiamondTrap::printStatus(void) {
    std::cout << DARK_GRAY "  =====================================" RESET << std::endl;
    std::cout << "    Name:\t" BOLD ORANGE << this->_name << RESET << std::endl;
    std::cout << "    HP:\t\t" << this->_hitPoints << std::endl;
    std::cout << "    EP:\t\t" << this->_energyPoints << std::endl;
    std::cout << "    DMG:\t" << this->_attackDamage << std::endl;
    std::cout << DARK_GRAY "  =====================================" RESET << std::endl;
};
