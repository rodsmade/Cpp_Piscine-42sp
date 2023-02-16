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
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate();
    void printStatus(void);
};
