#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    this->_name = "unnamed diamond trap";
    this->set_hit_points(FragTrap::DEFAULT_HIT_POINTS);
    this->set_energy_points(ScavTrap::DEFAULT_ENERGY_POINTS);
    this->set_attack_damage(FragTrap::DEFAULT_ATTACK_DAMAGE);
    std::cout << "DiamondTrap's default constructor called." << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    ClapTrap::set_name(name + "_clap_name");
    this->set_hit_points(FragTrap::DEFAULT_HIT_POINTS);
    this->set_energy_points(ScavTrap::DEFAULT_ENERGY_POINTS);
    this->set_attack_damage(FragTrap::DEFAULT_ATTACK_DAMAGE);
    std::cout << "DiamondTrap's name constructor called." << std::endl;
};

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap's default destructor called." << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
    this->set_name(other.get_name());
    this->set_hit_points(other.get_hit_points());
    this->set_energy_points(other.get_energy_points());
    this->set_attack_damage(other.get_attack_damage());
    std::cout << "DiamondTrap's copy constructor called." << std::endl;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "DiamondTrap's assignment operator (operator=) called." << std::endl;
    return (*this);
};

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << this->_name << " and my daddy's name is " << this->ClapTrap::_name << std::endl;
};

void DiamondTrap::print_status(void) {
    std::cout << "================================" << std::endl;
    std::cout << "Name:\t" << this->_name << std::endl;
    std::cout << "HP:\t" << this->get_hit_points() << std::endl;
    std::cout << "EP:\t" << this->get_energy_points() << std::endl;
    std::cout << "DMG:\t" << this->get_attack_damage() << std::endl;
    std::cout << "================================" << std::endl;
};
