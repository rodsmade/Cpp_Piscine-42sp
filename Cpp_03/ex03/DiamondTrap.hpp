#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
    std::string _name;

   public:
    using FragTrap::_attackDamage;
    using FragTrap::_hitPoints;
    using ScavTrap::_energyPoints;

    // Constructors/Destructor
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap(void);

    // Operator Overloads
    // -- Assignment operator
    DiamondTrap &operator=(const DiamondTrap &other);

    // Member functions
    using ScavTrap::ClapTrap::attack;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void whoAmI();
    void printStatus();
};
