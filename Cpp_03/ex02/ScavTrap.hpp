#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    // Constructors/Destructor
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap(void);

    // Member functions
    void guardGate();
};
