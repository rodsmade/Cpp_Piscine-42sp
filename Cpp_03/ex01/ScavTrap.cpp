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

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other.getName();
		this->_attackDamage = other.getAttackDamage();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
    }
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " has entered Gatekeeper Mode" << std::endl;
};

void ScavTrap::printStatus(void) {
    std::cout << "ScavTrap " << this->getName() << " has " << this->getHitPoints() << " HP and " << this->getEnergyPoints() << " energy" << std::endl;
};
