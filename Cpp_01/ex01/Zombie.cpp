#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("default") {
    Zombie::announce();
};

Zombie::~Zombie( void ) {
    std::cout << "Our mate " << this->_name << " is no longer among us." << std::endl;
};

std::string Zombie::getName( void ) {
    return (this->_name);
};

void Zombie::setName(std::string name) {
    this->_name = name;
    return ;
};

void Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

