#include "ClapTrap.hpp"

int main() {
	ClapTrap gandalf = ClapTrap("Gandalf");

	std::cout << "Gandalf has " << gandalf.getHitPoints() << " HP" << std::endl;
	std::cout << "Gandalf has " << gandalf.getEnergyPoints() << " energy" << std::endl;
	gandalf.attack("Balrog");
	std::cout << "Gandalf has " << gandalf.getHitPoints() << " HP" << std::endl;
	std::cout << "Gandalf has " << gandalf.getEnergyPoints() << " energy" << std::endl;

	gandalf.attack("Balrog");
	gandalf.attack("Balrog");
	std::cout << "Gandalf has " << gandalf.getHitPoints() << " HP" << std::endl;
	std::cout << "Gandalf has " << gandalf.getEnergyPoints() << " energy" << std::endl;
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
}
