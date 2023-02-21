#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cassert>

int main() {
    {
        std::cout << std::endl << BOLD BG_LIGHT_YELLOW "========================================= CLAPTRAP TESTS ==========" RESET << std::endl << std::endl;
        ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
        clepiClepi.printStatus();
        clepiClepi.attack("Rihanna");
        clepiClepi.attack("Rihanna");
        clepiClepi.attack("Rihanna");
        clepiClepi.attack("Rihanna");
        clepiClepi.attack("Rihanna");
        clepiClepi.beRepaired(1);
        clepiClepi.beRepaired(1);
        clepiClepi.beRepaired(1);
        clepiClepi.beRepaired(1);
        clepiClepi.beRepaired(1);
        clepiClepi.attack("Rihanna");
        clepiClepi.printStatus();

        ClapTrap clepiB = clepiClepi;  // same as ClapTrap clepiB = ClapTrap(clepiClepi);
        clepiB.setName("Clepi B");
        clepiClepi.printStatus();
        clepiB.setEnergyPoints(3);
        clepiB.printStatus();
        clepiClepi.printStatus();

        ClapTrap clepiC;  // same as ClapTrap clepiC = ClapTrap();
        clepiC = clepiB;
        clepiC.setName("Clépi C");
        clepiC.setAttackDamage(9999);
        clepiC.printStatus();
        clepiB.printStatus();
        clepiClepi.printStatus();
    }
    {
        std::cout << std::endl << BOLD BG_LIGHT_YELLOW "========================================= SCAVTRAP TESTS ==========" RESET << std::endl << std::endl;
        ClapTrap *base_ptr;

        ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
        base_ptr = &clepiClepi;
        clepiClepi.printStatus();
        base_ptr = &clepiClepi;
        base_ptr->printStatus();

        ScavTrap escave = ScavTrap("Escave");
        escave.printStatus();
        base_ptr = &escave;
        base_ptr->printStatus();
        escave.guardGate();
    }
    {
        std::cout << std::endl << BOLD BG_LIGHT_YELLOW "========================================= FRAGTRAP TESTS ==========" RESET << std::endl << std::endl;
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
        clepiClepi.takeDamage(speedy.getAttackDamage());
        clepiClepi.beRepaired(10);
        speedy.printStatus();
        clepiClepi.printStatus();
    }
    {
        DiamondTrap rihanna("Badgal Riri");
        FragTrap speedy("Speedy Fragger");
        ScavTrap escave("ScavTrap");

        std::cout << std::endl
                  << BOLD BG_LIGHT_YELLOW "====================================== DIAMONDTRAP TESTS ==========" RESET << std::endl
                  << std::endl;

        assert(rihanna.getHitPoints() == speedy.getHitPoints());
        assert(rihanna.getEnergyPoints() == escave.getEnergyPoints());
        assert(rihanna.getAttackDamage() == speedy.getAttackDamage());

        rihanna.printStatus();
        rihanna.ClapTrap::printStatus();
        rihanna.whoAmI();
        rihanna.attack("Victoria Secrets");
        rihanna.highFivesGuys();
    }

    return (0);
}