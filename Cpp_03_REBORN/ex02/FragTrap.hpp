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

    void attack(const std::string &target);
    void beRepaired(unsigned int amount);
    void printStatus(void);

    // FragTrap's exclusive function:
    void highFivesGuys(void);
};
