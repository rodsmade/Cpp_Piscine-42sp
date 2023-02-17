#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->set_hitPoints(FragTrap::DEFAULT_HIT_POINTS);
    this->set_energyPoints(FragTrap::DEFAULT_ENERGY_POINTS);
    this->set_attackDamage(FragTrap::DEFAULT_ATTACK_DAMAGE);
    std::cout << "FragTrap's default constructor called." << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->set_name(name);
    this->set_hitPoints(FragTrap::DEFAULT_HIT_POINTS);
    this->set_energyPoints(FragTrap::DEFAULT_ENERGY_POINTS);
    this->set_attackDamage(FragTrap::DEFAULT_ATTACK_DAMAGE);
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

void FragTrap::highFivesGuys(void) {
    std::cout << "High five my G's!" << std::endl;
};
