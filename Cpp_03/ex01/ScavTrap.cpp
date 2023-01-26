#include "ScavTrap.hpp"
// Toutefois, ses constructeurs, son destructeur et son attack() afficheront des messages différents.

// CONSTRUCTORS / DESTRUCTOR ===================================================
ScavTrap::ScavTrap(void) {
    this->_name = "undefined";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Default constructor called for ScavTrap " << this->getName() << std::endl;
};

ScavTrap::ScavTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Name constructor called for ScavTrap " << this->getName() << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "Copy constructor called for ScavTrap " << this->getName() << std::endl;
};

ScavTrap::~ScavTrap(void) {
    std::cout << "Destructor called for ScavTrap " << this->getName() << std::endl;
};

// MEMBER FUNCTIONS ============================================================
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " has entered Gatekeeper Mode" << std::endl;
};
