#pragma once

#include <iostream>

class ScavTrap: {
   private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

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

    //Getters e Setters
	std::string get_name(void);
	int get_hitPoints(void);
	int get_energyPoints(void);
	int get_attackDamage(void);
	void set_name(std::string name);
	void set_hitPoints(int hitPoints);
	void set_energyPoints(int energyPoints);
	void set_attackDamage(int attackDamage);


    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void printStatus(void);
};
