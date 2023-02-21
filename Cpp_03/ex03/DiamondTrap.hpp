#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
    std::string _name;

   public:
    // Constructors/Destructor
    DiamondTrap(void);
    DiamondTrap(std::string const name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap(void);

    // Operator Overloads
    // -- Assignment operator
    DiamondTrap &operator=(const DiamondTrap &other);

    // Member functions
    void whoAmI();
    void print_status(void);
};
