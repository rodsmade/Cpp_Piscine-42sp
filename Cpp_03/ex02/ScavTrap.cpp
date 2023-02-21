#include "ScavTrap.hpp"

// CONSTRUCTORS / DESTRUCTOR ===================================================
ScavTrap::ScavTrap() : ClapTrap() {
    this->_hitPoints = ScavTrap::DEFAULT_HIT_POINTS;
    this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
    this->_attackDamage = ScavTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << "'s default constructor called." << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hitPoints = ScavTrap::DEFAULT_HIT_POINTS;
    this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
    this->_attackDamage = ScavTrap::DEFAULT_ATTACK_DAMAGE;
    std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << "'s name constructor called." << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << "'s copy constructor called." << std::endl;
};

ScavTrap::~ScavTrap() {
    std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << "'s default destructor called." << std::endl;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_CYAN "ScavTrap" RESET "'s assignment operator (operator=) called." << std::endl;
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void ScavTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0) {
        std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << " has no energy left!" << std::endl;
        return;
    }
    this->_energyPoints = this->_energyPoints - 1;
    std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void ScavTrap::guardGate() {
    std::cout << LIGHT_CYAN "ScavTrap " RESET << this->_name << " is now on gate keeper mode." << std::endl;
};
