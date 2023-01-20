#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name){ };

HumanB::~HumanB( void ) { };

void HumanB::setWeapon( Weapon *weapon ) { this->_weapon = weapon;};

void HumanB::attack( void ) {
    std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
};