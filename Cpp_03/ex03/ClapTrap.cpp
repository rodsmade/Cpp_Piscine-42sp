#include "ClapTrap.hpp"

// CONSTRUCTORS / DESTRUCTOR ===================================================
ClapTrap::ClapTrap(void) : _name("unnamed clap trap"), _hitPoints(ClapTrap::DEFAULT_HIT_POINTS), _energyPoints(ClapTrap::DEFAULT_ENERGY_POINTS), _attackDamage(ClapTrap::DEFAULT_ATTACK_DAMAGE) {
    std::cout << LIGHT_BLUE "ClapTrap" RESET "'s default constructor called." << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(ClapTrap::DEFAULT_HIT_POINTS), _energyPoints(ClapTrap::DEFAULT_ENERGY_POINTS), _attackDamage(ClapTrap::DEFAULT_ATTACK_DAMAGE) {
    std::cout << LIGHT_BLUE "ClapTrap" RESET "'s name constructor called." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << LIGHT_BLUE "ClapTrap" RESET "'s copy constructor called." << std::endl;
};

ClapTrap::~ClapTrap() {
    std::cout << LIGHT_BLUE "ClapTrap" RESET "'s default destructor called." << std::endl;
};

// ACCESSORS ===================================================================
std::string ClapTrap::getName(void) const {
    return (this->_name);
};

int ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
};

int ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
};

int ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
};

void ClapTrap::setName(std::string name) {
    this->_name = name;
    return;
};

void ClapTrap::setEnergyPoints(int eps) {
    this->_energyPoints = eps;
    return;
};

void ClapTrap::setAttackDamage(int damage) {
    this->_attackDamage = damage;
    return;
};

// OPERATOR OVERLOADS ==========================================================
// ASSIGNMENT OPERATOR -------------------------------------------------
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << LIGHT_BLUE "ClapTrap" RESET "'s assignment operator (operator=) called." << std::endl;
    return (*this);
};

// MEMBER FUNCTIONS ============================================================
void ClapTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0) {
        std::cout << LIGHT_BLUE "ClapTrap " RESET << this->_name << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << LIGHT_BLUE "ClapTrap " RESET << this->_name << " has no energy left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << LIGHT_BLUE "ClapTrap " RESET << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (((int)(this->_hitPoints - amount)) < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << LIGHT_BLUE "ClapTrap " RESET << this->_name << " has no HP left!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << LIGHT_BLUE "ClapTrap " RESET << this->_name << " has no energy left!" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    std::cout << LIGHT_BLUE "ClapTrap " RESET << this->_name << " heals " << amount << " HP !" << std::endl;
};

void ClapTrap::printStatus(void) {
    std::cout << DARK_GRAY "  =====================================" RESET << std::endl;
    std::cout << "    Name:\t" BOLD VIOLET << this->_name << RESET << std::endl;
    std::cout << "    HP:\t\t" << this->_hitPoints << std::endl;
    std::cout << "    EP:\t\t" << this->_energyPoints << std::endl;
    std::cout << "    DMG:\t" << this->_attackDamage << std::endl;
    std::cout << DARK_GRAY "  =====================================" RESET << std::endl;
};
