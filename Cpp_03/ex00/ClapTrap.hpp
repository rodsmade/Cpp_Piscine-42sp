#pragma once

#include <iostream>

#define BOLD "\033[1m"
#define ORANGE "\033[38;2;255;165;0m"
#define VIOLET "\033[38;2;75;0;130m"
#define DARK_GRAY "\033[90m"
#define BG_LIGHT_YELLOW "\033[103m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_RED "\033[91m"
#define RESET "\033[0m"

class ClapTrap {
   private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
    const static int DEFAULT_HIT_POINTS = 10;
    const static int DEFAULT_ENERGY_POINTS = 10;
    const static int DEFAULT_ATTACK_DAMAGE = 0;

   public:
    // Constructors/Destructor
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap(void);

    // Accessors
    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;
    void setName(std::string name);
    void setEnergyPoints(int eps);
    void setAttackDamage(int damage);

    // Operator Overloads
    // -- Assignment operator
    ClapTrap &operator=(const ClapTrap &other);

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void printStatus(void);
};
