#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

   public:
    // construtor
    ScavTrap();
    ScavTrap(std::string name);
    // destrutor
    ~ScavTrap();
    // copy constructor
    ScavTrap(const ScavTrap &other);
    // operator=
    ScavTrap &operator=(const ScavTrap &other);

    void attack(const std::string &target);

    // ScavTrap's exclusive function:
    void guardGate();

   private:
    const static int DEFAULT_HIT_POINTS = 100;
    const static int DEFAULT_ENERGY_POINTS = 50;
    const static int DEFAULT_ATTACK_DAMAGE = 20;
};
