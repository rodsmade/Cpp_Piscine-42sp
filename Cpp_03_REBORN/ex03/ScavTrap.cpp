#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->set_hitPoints(this->DEFAULT_HIT_POINTS);
    this->set_energyPoints(this->DEFAULT_ENERGY_POINTS);
    this->set_attackDamage(this->DEFAULT_ATTACK_DAMAGE);
    std::cout << "ScavTrap's default constructor called." << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->set_name(name);
    this->set_hitPoints(this->DEFAULT_HIT_POINTS);
    this->set_energyPoints(this->DEFAULT_ENERGY_POINTS);
    this->set_attackDamage(this->DEFAULT_ATTACK_DAMAGE);
    std::cout << "ScavTrap's name constructor called." << std::endl;
};

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap's default destructor called." << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) {
    this->set_name(other.get_name());
    this->set_hitPoints(other.get_hitPoints());
    this->set_energyPoints(other.get_energyPoints());
    this->set_attackDamage(other.get_attackDamage());
    std::cout << "ScavTrap's copy constructor called." << std::endl;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "ScavTrap's assignment operator (operator=) called." << std::endl;
    return (*this);
};

void ScavTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->get_name() << " is now on gate keeper mode." << std::endl;
};
