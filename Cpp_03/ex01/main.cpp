#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap gandalf = ClapTrap("Gandalf");
    ScavTrap balrog = ScavTrap("Balrog");
    gandalf.printStatus();
    balrog.printStatus();
    std::cout << std::endl;

    balrog.guardGate();
    gandalf.attack("Balrog");
    std::cout << std::endl;

    gandalf.printStatus();
    balrog.printStatus();
    std::cout << std::endl;

    ScavTrap anotherBalrog;
    anotherBalrog = ScavTrap(balrog);
    anotherBalrog.setName("Another Balrog");
    anotherBalrog.guardGate();
    anotherBalrog.printStatus();
}
