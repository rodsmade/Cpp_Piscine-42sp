#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
    this->_energyPoints = FragTrap::DEFAULT_ENERGY_POINTS;
    this->_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << LIGHT_MAGENTA "FragTrap" RESET "'s default constructor called." << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
    this->_energyPoints = FragTrap::DEFAULT_ENERGY_POINTS;
    this->_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << LIGHT_MAGENTA "FragTrap" RESET "'s name constructor called." << std::endl;
};

FragTrap::~FragTrap() {
    std::cout << LIGHT_MAGENTA "FragTrap" RESET "'s default destructor called." << std::endl; 
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_MAGENTA "FragTrap" RESET "'s copy constructor called." << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_MAGENTA "FragTrap" RESET "'s assignment operator (operator=) called." << std::endl;
    return (*this);
};

void FragTrap::highFivesGuys(void) {
    std::cout << LIGHT_MAGENTA "FragTrap " RESET << this->_name << " says: High five, my G's!" << std::endl;
};
