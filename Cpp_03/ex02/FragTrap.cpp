#include "FragTrap.hpp"
// Toutefois, ses constructeurs, son destructeur et son attack() afficheront des messages différents.

// CONSTRUCTORS / DESTRUCTOR ===================================================
FragTrap::FragTrap(void) {
    this->_name = "undefined";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Default constructor called for FragTrap " << this->getName() << std::endl;
};

FragTrap::FragTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Name constructor called for FragTrap " << this->getName() << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "Copy constructor called for FragTrap " << this->getName() << std::endl;
};

FragTrap::~FragTrap(void) {
    std::cout << "Destructor called for FragTrap " << this->getName() << std::endl;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_attackDamage = other.getAttackDamage();
        this->_hitPoints = other.getHitPoints();
        this->_energyPoints = other.getEnergyPoints();
    }
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void FragTrap::attack(const std::string &target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "FragTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "FragTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void FragTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoints() > 0) {
        std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->setHitPoints(this->getHitPoints() - amount);
    } else {
        std::cout << "FragTrap " << this->getName() << " has no HP left!" << std::endl;
    }
};

void FragTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "FragTrap " << this->_name << " heals " << amount << " hit points." << std::endl;
        this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "FragTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "FragTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void FragTrap::highFivesGuys(void) {
    std::cout << "High Five, my G's!" << std::endl;
};

void FragTrap::printStatus(void) {
    std::cout << "FragTrap " << this->getName() << " has " << this->getHitPoints() << " HP and " << this->getEnergyPoints() << " energy" << std::endl;
};
