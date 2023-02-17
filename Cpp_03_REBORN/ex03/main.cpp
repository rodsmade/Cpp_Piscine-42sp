#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cassert>

int main() {
    {
        std::cout << std::endl << "========================================= ClapTrap Tests ==========" << std::endl << std::endl;
        ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
        clepiClepi.print_status();
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
        clepiClepi.print_status();

        ClapTrap clepiB = clepiClepi;  // same as ClapTrap clepiB = ClapTrap(clepiClepi);
        clepiB.set_name("Clepi B");
        clepiB.set_energy_points(3);
        clepiB.print_status();
        clepiClepi.print_status();

        ClapTrap clepiC;  // same as ClapTrap clepiC = ClapTrap();
        clepiC = clepiB;
        clepiC.set_name("Clépi C");
        clepiC.set_attack_damage(9999);
        clepiC.print_status();
        clepiB.print_status();
        clepiClepi.print_status();
    }
    {
        std::cout << std::endl << "========================================= ScavTrap Tests ==========" << std::endl << std::endl;
        ClapTrap *base_ptr;

        ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
        base_ptr = &clepiClepi;
        clepiClepi.print_status();
        base_ptr = &clepiClepi;
        base_ptr->print_status();

        ScavTrap escave = ScavTrap("Escave");
        escave.print_status();
        base_ptr = &escave;
        base_ptr->print_status();
        escave.guardGate();
    }
    {
        std::cout << std::endl << "========================================= FragTrap Tests ==========" << std::endl << std::endl;
        ClapTrap *base_ptr;

        ClapTrap clepiClepi = ClapTrap("Crépe-crépe");
        base_ptr = &clepiClepi;
        // clepiClepi.print_status();
        base_ptr = &clepiClepi;
        // base_ptr->print_status();

        FragTrap speedy = FragTrap("Speedy Fragger");
        // speedy.print_status();
        base_ptr = &speedy;
        // base_ptr->print_status();
        speedy.highFivesGuys();

        speedy.attack("Crépe-crépe");
        clepiClepi.takeDamage(speedy.get_attack_damage());
        clepiClepi.beRepaired(10);
        // speedy.print_status();
        // clepiClepi.print_status();
    }
    {
        DiamondTrap rihanna("Badgal Riri");
        FragTrap speedy("Speedy Fragger");
        ScavTrap escave("ScavTrap");

        std::cout << std::endl
                  << "====================================== DiamondTrap Tests ==========" << std::endl
                  << std::endl;

        assert(rihanna.get_hit_points() == speedy.get_hit_points());
        assert(rihanna.get_energy_points() == escave.get_energy_points());
        assert(rihanna.get_attack_damage() == speedy.get_attack_damage());

        rihanna.print_status();
        rihanna.whoAmI();
        rihanna.attack("Victoria Secrets");
        rihanna.highFivesGuys();
    }

    return (0);
}