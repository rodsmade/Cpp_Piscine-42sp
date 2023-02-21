#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap gandalf = ClapTrap("Gandalf");
    ScavTrap balrog = ScavTrap("Balrog");
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
    std::cout << std::endl;

    balrog.guardGate();
    gandalf.attack("Balrog");
    balrog.takeDamage(gandalf.getAttackDamage());
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
    std::cout << std::endl;

    ScavTrap anotherBalrog;
    anotherBalrog = ScavTrap(balrog);
    anotherBalrog.setName("Another Balrog");
    std::cout << std::endl;

    anotherBalrog.guardGate();
    anotherBalrog.printStatus();
    anotherBalrog.attack("Balrog");
    balrog.takeDamage(anotherBalrog.getAttackDamage());
    std::cout << std::endl;

    balrog.printStatus();
    anotherBalrog.printStatus();
    std::cout << std::endl;
}
