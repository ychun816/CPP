#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << _name << "Zombie is Created!" << std::endl;//created
}

Zombie::~Zombie()
{
    std::cout << _name << "Zombie is Destryoed!" << std::endl;//destroyed
}

//setname
void    Zombie::setName(std::string name)
{
    _name = name;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//Dynamically allocate/create a Zombie on the heap using new
//Assign a name to the zombie
//Return a pointer to the newly created zombie
//arrow operator, used to access members of an object through a pointer.
Zombie* Zombie::newZombie( std::string name )
{
    Zombie *zb_heap = new Zombie();// Allocate on heap
    zb_heap->setName(name);
    return (newZombie);
}

void    Zombie::randomChump(std::string name)
{
    Zombie zb_stack;
    zb_stack.setName(name);
    zb_stack.announce();
}
