#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA alabaster("Alabaster", &club);
        alabaster.attack();
        club.setType("some other type of club");
        alabaster.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB bob("Bob");
        bob.setWeapon(&club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    return 0;
}