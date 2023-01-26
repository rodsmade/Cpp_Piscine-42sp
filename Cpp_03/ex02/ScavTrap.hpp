#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    // Constructors/Destructor
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap(void);

    // Operator Overloads
    // -- Assignment operator
    ScavTrap &operator=(const ScavTrap &other);

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate();
    void printStatus();
};
