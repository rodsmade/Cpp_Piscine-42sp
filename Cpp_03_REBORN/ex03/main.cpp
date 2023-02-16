#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // {
    //     std::cout << std::endl << "========================================= ClapTrap Tests ==========" << std::endl << std::endl;
    //     ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
    //     clepiClepi.printStatus();
    //     clepiClepi.attack("Rihanna");
    //     clepiClepi.attack("Rihanna");
    //     clepiClepi.attack("Rihanna");
    //     clepiClepi.attack("Rihanna");
    //     clepiClepi.attack("Rihanna");
    //     clepiClepi.beRepaired(1);
    //     clepiClepi.beRepaired(1);
    //     clepiClepi.beRepaired(1);
    //     clepiClepi.beRepaired(1);
    //     clepiClepi.beRepaired(1);
    //     clepiClepi.attack("Rihanna");
    //     clepiClepi.printStatus();

    //     ClapTrap clepiB = clepiClepi;  // same as ClapTrap clepiB = ClapTrap(clepiClepi);
    //     clepiB.set_name("Clepi B");
    //     clepiB.set_energyPoints(3);
    //     clepiB.printStatus();
    //     clepiClepi.printStatus();

    //     ClapTrap clepiC;  // same as ClapTrap clepiC = ClapTrap();
    //     clepiC = clepiB;
    //     clepiC.set_name("Clépi C");
    //     clepiC.set_attackDamage(9999);
    //     clepiC.printStatus();
    //     clepiB.printStatus();
    //     clepiClepi.printStatus();
    // }
    // {
    //     std::cout << std::endl << "========================================= ScavTrap Tests ==========" << std::endl << std::endl;
    //     ClapTrap *base_ptr;speedy

    //     ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
    //     base_ptr = &clepiClepi;
    //     clepiClepi.printStatus();
    //     base_ptr = &clepiClepi;
    //     base_ptr->printStatus();

    //     ScavTrap escave = ScavTrap("Escave");
    //     escave.printStatus();
    //     base_ptr = &escave;
    //     base_ptr->printStatus();
    //     escave.guardGate();
    // }
    {
        std::cout << std::endl << "========================================= FragTrap Tests ==========" << std::endl << std::endl;
        ClapTrap *base_ptr;

        ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
        base_ptr = &clepiClepi;
        clepiClepi.printStatus();
        base_ptr = &clepiClepi;
        base_ptr->printStatus();

        FragTrap speedy = FragTrap("Speedy Fragger");
        speedy.printStatus();
        base_ptr = &speedy;
        base_ptr->printStatus();
        speedy.highFivesGuys();

        speedy.attack("Crépe-crépe");
        clepiClepi.takeDamage(speedy.get_attackDamage());
        clepiClepi.beRepaired(10);
        speedy.printStatus();
        clepiClepi.printStatus();
    }

    return (0);
}