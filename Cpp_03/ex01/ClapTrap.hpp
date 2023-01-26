#pragma once

#include <iostream>

class ClapTrap {
   protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

   public:
    // Constructors/Destructor
    ClapTrap(void);
    ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
    ~ClapTrap(void);

    // Accessors
    std::string getName(void) const;
    void setName(std::string const name);
    int getHitPoints(void) const;
    void setHitPoints(int const hitPoints);
    int getEnergyPoints(void) const;
    void setEnergyPoints(int const energyPoints);
    int getAttackDamage(void) const;
    void setAttackDamage(int const attackDamage);

    // Operator Overloads
    // -- Assignment operator
    ClapTrap &operator=(const ClapTrap &other);

    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

	void printStatus(void);
};
