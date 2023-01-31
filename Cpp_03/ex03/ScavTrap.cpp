#include "ScavTrap.hpp"
// Toutefois, ses constructeurs, son destructeur et son attack() afficheront des messages différents.

// CONSTRUCTORS / DESTRUCTOR ===================================================
ScavTrap::ScavTrap(void) {
    this->_name = "undefined";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Default constructor called for ScavTrap " << this->getName() << std::endl;
};

ScavTrap::ScavTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Name constructor called for ScavTrap " << this->getName() << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "Copy constructor called for ScavTrap " << this->getName() << std::endl;
};

ScavTrap::~ScavTrap(void) {
    std::cout << "Destructor called for ScavTrap " << this->getName() << std::endl;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_attackDamage = other.getAttackDamage();
        this->_hitPoints = other.getHitPoints();
        this->_energyPoints = other.getEnergyPoints();
    }
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void ScavTrap::attack(const std::string &target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "ScavTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "ScavTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoints() > 0) {
        std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->setHitPoints(this->getHitPoints() - amount);
    } else {
        std::cout << "ScavTrap " << this->getName() << " has no HP left!" << std::endl;
    }
};

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "ScavTrap " << this->_name << " heals " << amount << " hit points." << std::endl;
        this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "ScavTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "ScavTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " has entered Gatekeeper Mode" << std::endl;
};

void ScavTrap::printStatus(void) {
    std::cout << "ScavTrap " << this->getName() << " has " << this->getHitPoints() << " HP and " << this->getEnergyPoints() << " energy and " << this->getAttackDamage() << " attack damage" << std::endl;
};
