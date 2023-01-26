#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap gandalf = ClapTrap("Gandalf");
    ScavTrap balrog = ScavTrap("Balrog");
    FragTrap speedy = FragTrap("Speedy Fragger");
    gandalf.printStatus();
    balrog.printStatus();
    speedy.printStatus();
    std::cout << std::endl;

    speedy.highFivesGuys();
    std::cout << std::endl;
}
