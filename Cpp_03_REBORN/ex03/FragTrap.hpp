#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
   public:
    // construtor
    FragTrap();
    FragTrap(std::string name);
    // destrutor
    ~FragTrap();
    // copy constructor
    FragTrap(const FragTrap &other);
    // operator=
    FragTrap &operator=(const FragTrap &other);

    // FragTrap's exclusive function:
    void highFivesGuys(void);

   private:
    const static int DEFAULT_HIT_POINTS = 100;
    const static int DEFAULT_ENERGY_POINTS = 100;
    const static int DEFAULT_ATTACK_DAMAGE = 30;
};
