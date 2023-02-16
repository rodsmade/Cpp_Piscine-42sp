#pragma once

#include <iostream>

class ClapTrap {
   private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

   public:
    // construtor
    ClapTrap(std::string name);
    // destrutor
    ~ClapTrap();
    // copy constructor
    ClapTrap(const ClapTrap &other);
    // operator=
    ClapTrap &operator=(const ClapTrap &other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
