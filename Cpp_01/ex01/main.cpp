#include "Zombie.hpp"
#include "zombieHorde.cpp"

int main()
{
    Zombie *horde = zombieHorde(42, "arnaldo");

    delete [] horde ;
}