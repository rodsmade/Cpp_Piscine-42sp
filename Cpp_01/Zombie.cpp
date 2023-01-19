#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
    Zombie::announce();
};

Zombie::~Zombie( void ) {
    std::cout << "Our mate " << this->_name << " is no longer among us." << std::endl;
};

void Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
