#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap gandalf = ClapTrap("Gandalf");
    ScavTrap balrog = ScavTrap("Balrog");
    FragTrap speedy = FragTrap("Speedy Fragger");
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
    speedy.printStatus();
    std::cout << std::endl;

    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    balrog.attack("Gandalf");
    gandalf.takeDamage(balrog.getAttackDamage());
    gandalf.beRepaired(10);
    std::cout << std::endl;

    balrog.attack("Speedy Fragger");
    speedy.takeDamage(balrog.getAttackDamage());
    speedy.attack("Balrog");
    balrog.takeDamage(speedy.getAttackDamage());
    speedy.attack("Balrog");
    balrog.takeDamage(speedy.getAttackDamage());
    balrog.attack("Speedy Fragger");
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
    speedy.printStatus();
    std::cout << std::endl;

    speedy.highFivesGuys();
    std::cout << std::endl;
}
