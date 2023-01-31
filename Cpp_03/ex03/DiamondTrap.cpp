#include "DiamondTrap.hpp"

// CONSTRUCTORS / DESTRUCTOR ===================================================
DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
    std::cout << "Default constructor called for DiamondTrap " << this->getName() << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->_attackDamage = FragTrap::getAttackDamage();
    this->_hitPoints = FragTrap::getHitPoints();
    this->_energyPoints = ScavTrap::getEnergyPoints();
    std::cout << "Name constructor called for DiamondTrap " << this->getName() << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    *this = other;
    std::cout << "Copy constructor called for DiamondTrap " << this->getName() << std::endl;
};

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Destructor called for DiamondTrap " << this->getName() << std::endl;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_attackDamage = other.getAttackDamage();
        this->_hitPoints = other.getHitPoints();
        this->_energyPoints = other.getEnergyPoints();
    }
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void DiamondTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoints() > 0) {
        std::cout << "DiamondTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->setHitPoints(this->getHitPoints() - amount);
    } else {
        std::cout << "DiamondTrap " << this->getName() << " has no HP left!" << std::endl;
    }
};

void DiamondTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "DiamondTrap " << this->_name << " heals " << amount << " hit points." << std::endl;
        this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "DiamondTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "DiamondTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void DiamondTrap::whoAmI(void) {
    std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
    std::cout << "DiamondTrap's name: " << this->_name << std::endl;
};

void DiamondTrap::printStatus(void) {
    std::cout << "DiamondTrap " << this->getName() << " has " << this->getHitPoints() << " HP and " << this->getEnergyPoints() << " energy and " << this->getAttackDamage() << " attack damage" << std::endl;
};
