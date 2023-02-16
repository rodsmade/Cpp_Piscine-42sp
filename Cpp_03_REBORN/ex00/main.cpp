#include "ClapTrap.hpp"

int main(){
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

	ClapTrap clepiB = clepiClepi; // same as ClapTrap clepiB = ClapTrap(clepiClepi);
	clepiB.set_name("Clepi B");
	clepiB.set_energyPoints(3);
	clepiB.printStatus();
	clepiClepi.printStatus();


	ClapTrap clepiC; // same as ClapTrap clepiC = ClapTrap();
	clepiC = clepiB;
	clepiC.set_name("Clépi C");
	clepiC.set_attackDamage(9999);
	clepiC.printStatus();
	clepiB.printStatus();
	clepiClepi.printStatus();

	return (0);
}