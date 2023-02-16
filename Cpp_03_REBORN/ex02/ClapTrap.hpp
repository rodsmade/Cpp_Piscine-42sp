#pragma once

#include <iostream>

class ClapTrap {
   protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

   public:
    // construtor
    ClapTrap();
    ClapTrap(std::string name);
    // destrutor
    ~ClapTrap();
    // copy constructor
    ClapTrap(const ClapTrap &other);
    // operator=
    ClapTrap &operator=(const ClapTrap &other);

    // Getters e Setters
    std::string get_name(void) const;
    int get_hitPoints(void) const;
    int get_energyPoints(void) const;
    int get_attackDamage(void) const;
    void set_name(std::string name);
    void set_hitPoints(int hitPoints);
    void set_energyPoints(int energyPoints);
    void set_attackDamage(int attackDamage);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
    virtual void printStatus(void);
};
