#include "Zombie.hpp"

// Allocate an array of N zombies in a single allocation
// Initialize each zombie with the given name
// Return pointer to the first zombie

// Zombie* newZombie( std::string name )
// {
//     Zombie *zb_heap = new Zombie();// Allocate on heap
//     zb_heap->setName(name);
//     return (zb_heap);
// }

Zombie*    zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    // std::getline(std::cin, name);

    //loop to setName for each zombies
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}