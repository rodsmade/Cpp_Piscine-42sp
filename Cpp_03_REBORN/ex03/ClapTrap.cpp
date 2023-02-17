#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unnamed clap trap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
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

int ClapTrap::get_hit_points(void) const {
    return (this->_hitPoints);
};

int ClapTrap::get_energy_points(void) const {
    return (this->_energyPoints);
};

int ClapTrap::get_attack_damage(void) const {
    return (this->_attackDamage);
};

void ClapTrap::set_name(std::string name) {
    this->_name = name;
};

void ClapTrap::set_hit_points(int hitPoints) {
    this->_hitPoints = hitPoints;
};

void ClapTrap::set_energy_points(int energyPoints) {
    this->_energyPoints = energyPoints;
};

void ClapTrap::set_attack_damage(int attackDamage) {
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

void    ClapTrap::print_status(void) {
    std::cout << "================================" << std::endl;
    std::cout << "Name:\t" << this->get_name() << std::endl;
    std::cout << "HP:\t" << this->get_hit_points() << std::endl;
    std::cout << "EP:\t" << this->get_energy_points() << std::endl;
    std::cout << "DMG:\t" << this->get_attack_damage() << std::endl;
    std::cout << "================================" << std::endl;
};