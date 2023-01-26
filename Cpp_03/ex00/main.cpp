#include "ClapTrap.hpp"

int main() {
	ClapTrap gandalf = ClapTrap("Gandalf");

	gandalf.printStatus();
	std::cout << std::endl;
	
	gandalf.attack("Balrog");
	gandalf.printStatus();
	gandalf.attack("Balrog");
	gandalf.attack("Balrog");
	gandalf.printStatus();
	std::cout << std::endl;

	gandalf.takeDamage(9);
	gandalf.printStatus();
	std::cout << std::endl;

	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	gandalf.beRepaired(1);
	std::cout << std::endl;
	gandalf.printStatus();
}
