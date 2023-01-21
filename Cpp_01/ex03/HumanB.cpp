#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){};

HumanB::~HumanB(void){};

void HumanB::setWeapon(Weapon *weapon) { this->_weapon = weapon; };

void HumanB::attack(void) {
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
    else
        std::cout << this->_name << " attacks with their ... oops! They got nothing on 'em!";
};