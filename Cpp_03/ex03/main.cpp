#include "DiamondTrap.hpp"

int main() {
    ClapTrap clap = ClapTrap("Clapper");
    ScavTrap scav = ScavTrap("Scavver");
    FragTrap frag = FragTrap("Fragger");
    DiamondTrap diamong = DiamondTrap("Rihanna");
	std::cout << std::endl;

    clap.printStatus();
    scav.printStatus();
    frag.printStatus();
    diamong.printStatus();
	std::cout << std::endl;
}
