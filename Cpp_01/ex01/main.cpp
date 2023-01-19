#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) ;

int main()
{
    int     hordeSize = 3;
    Zombie *horde = zombieHorde(hordeSize, "Army");

    for (int i = 0; i < hordeSize; i++) {
        horde[i].announce();
    }

    delete [] horde ;
}