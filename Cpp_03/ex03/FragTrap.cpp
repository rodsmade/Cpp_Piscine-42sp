#include "FragTrap.hpp"
// Toutefois, ses constructeurs, son destructeur et son attack() afficheront des messages différents.

// CONSTRUCTORS / DESTRUCTOR ===================================================
FragTrap::FragTrap(void) {
    this->_name = "undefined";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Default constructor called for FragTrap " << this->getName() << std::endl;
};

FragTrap::FragTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Name constructor called for FragTrap " << this->getName() << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "Copy constructor called for FragTrap " << this->getName() << std::endl;
};

FragTrap::~FragTrap(void) {
    std::cout << "Destructor called for FragTrap " << this->getName() << std::endl;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_attackDamage = other.getAttackDamage();
        this->_hitPoints = other.getHitPoints();
        this->_energyPoints = other.getEnergyPoints();
    }
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void FragTrap::highFivesGuys(void) {
    std::cout << "High Five, my G's!" << std::endl;
};

void FragTrap::printStatus(void) {
    std::cout << "FragTrap " << this->getName() << " has " << this->getHitPoints() << " HP and " << this->getEnergyPoints() << " energy" << std::endl;
};
