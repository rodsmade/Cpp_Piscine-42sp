#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : protected ScavTrap, protected FragTrap {
   private:
    std::string _name;

   public:
    DiamondTrap();
    DiamondTrap(std::string const name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);

    void whoAmI();
};
