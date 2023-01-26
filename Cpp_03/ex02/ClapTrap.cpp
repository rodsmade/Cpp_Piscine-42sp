#include "ClapTrap.hpp"

// CONSTRUCTORS / DESTRUCTOR ===================================================
ClapTrap::ClapTrap(void) : _name("undefined"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called for ClapTrap " << this->getName() << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Name constructor called for ClapTrap " << this->getName() << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "Copy constructor called for ClapTrap " << this->getName() << std::endl;
    *this = other;
};

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called for ClapTrap " << this->getName() << std::endl;
};

// ACCESSORS ===================================================================
std::string ClapTrap::getName(void) const {
    return (this->_name);
};

void ClapTrap::setName(std::string const name) {
    this->_name = name;
};

int ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
};

void ClapTrap::setHitPoints(int const hitPoints) {
    this->_hitPoints = hitPoints;
};

int ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
};

void ClapTrap::setEnergyPoints(int const energyPoints) {
    this->_energyPoints = energyPoints;
};

int ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
};

void ClapTrap::setAttackDamage(int const attackDamage) {
    this->_attackDamage = attackDamage;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other.getName();
    }
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void ClapTrap::attack(const std::string &target) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "ClapTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "ClapTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoints() > 0) {
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->setHitPoints(this->getHitPoints() - amount);
    } else {
        std::cout << "ClapTrap " << this->getName() << " has no HP left!" << std::endl;
    }
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0) {
        std::cout << "ClapTrap " << this->_name << " heals " << amount << " hit points." << std::endl;
        this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        if (this->getHitPoints() <= 0) {
            std::cout << "ClapTrap " << this->getName() << " has no HP left!" << std::endl;
        } else {
            std::cout << "ClapTrap " << this->getName() << " has no Energy Points left to perform this action!" << std::endl;
        }
    }
};

void ClapTrap::printStatus(void) {
    std::cout << "ClapTrap " << this->getName() << " has " << this->getHitPoints() << " HP" << std::endl;
    std::cout << "ClapTrap " << this->getName() << " has " << this->getEnergyPoints() << " energy" << std::endl;
};
