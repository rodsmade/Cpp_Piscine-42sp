#include "Zombie.hpp"

Zombie* newZombie( std::string name ) ;
void randomChump( std::string name ) ;

int main()
{
    Zombie aroldo = Zombie("Aroldo");
    Zombie *etoale = new Zombie("Etoale");

    std::cout << "New Zombie:" << std::endl;
    Zombie *alaor = newZombie("Alaor");
    std::cout << "Random Chump" << std::endl;
    randomChump("Randy");

    delete etoale;
    delete alaor;
}