#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
   public:
    using ClapTrap::_hitPoints;
    using ClapTrap::_attackDamage;

    // Constructors/Destructor
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    ~FragTrap(void);

    // Operator Overloads
    // -- Assignment operator
    FragTrap &operator=(const FragTrap &other);

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys(void);
    void printStatus();
};
