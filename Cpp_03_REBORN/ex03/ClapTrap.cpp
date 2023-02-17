#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("undefined"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap's default constructor called." << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap's name constructor called." << std::endl;
};

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap's default destructor called." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap's copy constructor called." << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "ClapTrap's assignment operator (operator=) called." << std::endl;
    return (*this);
};

std::string ClapTrap::get_name(void) const {
    return (this->_name);
};

int ClapTrap::get_hitPoints(void) const {
    return (this->_hitPoints);
};

int ClapTrap::get_energyPoints(void) const {
    return (this->_energyPoints);
};

int ClapTrap::get_attackDamage(void) const {
    return (this->_attackDamage);
};

void ClapTrap::set_name(std::string name) {
    this->_name = name;
};

void ClapTrap::set_hitPoints(int hitPoints) {
    this->_hitPoints = hitPoints;
};

void ClapTrap::set_energyPoints(int energyPoints) {
    this->_energyPoints = energyPoints;
};

void ClapTrap::set_attackDamage(int attackDamage) {
    this->_attackDamage = attackDamage;
};

void ClapTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (((int)(this->_hitPoints - amount)) < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy left!" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " heals " << amount << " HP !" << std::endl;
};

