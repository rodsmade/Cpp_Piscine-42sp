#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
   protected:
    const static int DEFAULT_HIT_POINTS = 100;
    const static int DEFAULT_ENERGY_POINTS = 100;
    const static int DEFAULT_ATTACK_DAMAGE = 30;

   public:
    // Constructors/Destructor
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    ~FragTrap();

    // Operator Overloads
    // -- Assignment operator
    FragTrap &operator=(const FragTrap &other);

    // Member functions
    void highFivesGuys(void);
};
