#include "ScavTrap.hpp"

int main() {
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

    return (0);
}