#include "ClapTrap.hpp"

int main() {
    ClapTrap gandalf = ClapTrap("Gandalf");
    ClapTrap balrog = ClapTrap(gandalf);
    balrog.setName("Balrog");

    gandalf.printStatus();
    balrog.printStatus();
    std::cout << std::endl;

    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
    std::cout << std::endl;

    balrog.setAttackDamage(9);
    balrog.attack("Gandalf");
    gandalf.takeDamage(balrog.getAttackDamage());
    gandalf.printStatus();
    std::cout << std::endl;

    gandalf.beRepaired(1);
    gandalf.beRepaired(1);
    gandalf.beRepaired(1);
    gandalf.beRepaired(1);
    gandalf.beRepaired(1);
    gandalf.beRepaired(1);
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
}
