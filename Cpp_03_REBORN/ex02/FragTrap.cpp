#include "FragTrap.hpp"

FragTrap::FragTrap() {
    this->set_hitPoints(100);
    this->set_energyPoints(100);
    this->set_attackDamage(30);
    std::cout << "FragTrap's default constructor called." << std::endl;
};

FragTrap::FragTrap(std::string name) {
    this->set_name(name);
    this->set_hitPoints(100);
    this->set_energyPoints(100);
    this->set_attackDamage(30);
    std::cout << "FragTrap's name constructor called." << std::endl;
};

FragTrap::~FragTrap() {
    std::cout << "FragTrap's default destructor called." << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) {
    this->set_name(other.get_name());
    this->set_hitPoints(other.get_hitPoints());
    this->set_energyPoints(other.get_energyPoints());
    this->set_attackDamage(other.get_attackDamage());
    std::cout << "FragTrap's copy constructor called." << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "FragTrap's assignment operator (operator=) called." << std::endl;
    return (*this);
};

void FragTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->get_name() << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "FragTrap " << this->get_name() << " has no energy left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "FragTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_attackDamage() << " points of damage!" << std::endl;
};

void FragTrap::beRepaired(unsigned int amount){
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->get_name() << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "FragTrap " << this->get_name() << " has no energy left!" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    std::cout << "FragTrap " << this->get_name() << " heals " << amount << " HP !" << std::endl;
};

void FragTrap::printStatus(void) {
    std::cout << std::endl;
    std::cout << "FragTrap " << this->get_name() << " has:" << std::endl;
    std::cout << "  " << this->get_attackDamage() << " attack damage;" << std::endl;
    std::cout << "  " << this->get_energyPoints() << " energy points;" << std::endl;
    std::cout << "  " << this->get_hitPoints() << " hit points;" << std::endl;
    std::cout << std::endl;
};

void FragTrap::highFivesGuys(void) {
    std::cout << "High five my G's!" << std::endl;
};
