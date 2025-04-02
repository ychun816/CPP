#include "Zombie.hpp"

/**
 * Dynamically allocate/create a Zombie on HEAP (with using new)
 * Assign a name to the zombie
 * Return a pointer to the newly created zombie
 * @note -> arrow operator : like chainlist, to access members of an object through a pointer
 */
Zombie* newZombie( std::string name )
{
    Zombie *zb_heap = new Zombie();
    zb_heap->setName(name);
    return (zb_heap);
}