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
    int get_hit_points(void) const;
    int get_energy_points(void) const;
    int get_attack_damage(void) const;
    void set_name(std::string name);
    void set_hit_points(int hitPoints);
    void set_energy_points(int energyPoints);
    void set_attack_damage(int attackDamage);

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void print_status( void );
};
