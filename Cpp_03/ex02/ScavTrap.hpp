#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
   protected:
    const static int DEFAULT_HIT_POINTS = 100;
    const static int DEFAULT_ENERGY_POINTS = 50;
    const static int DEFAULT_ATTACK_DAMAGE = 20;

   public:
    // Constructors/Destructor
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();

    // Operator Overloads
    // -- Assignment operator
    ScavTrap &operator=(const ScavTrap &other);

    // Member functions
    void attack(const std::string &target);
    void guardGate();
};
