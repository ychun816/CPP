#include "Zombie.hpp"

/** INSTRUCTIONS
 * Allocate an array of N zombies in a single allocation
 * Initialize each zombie with the given name
 * Return pointer to the first zombie
 * -> loop to setName for each zombies
 */

Zombie*    zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}