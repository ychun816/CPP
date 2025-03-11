#include "Zombie.hpp"

//Dynamically allocate/create a Zombie on the heap using new
//Assign a name to the zombie
//Return a pointer to the newly created zombie
//arrow operator, used to access members of an object through a pointer.
Zombie* newZombie( std::string name )
{
    Zombie *zb_heap = new Zombie();// Allocate on heap
    zb_heap->setName(name);
    return (zb_heap);
}