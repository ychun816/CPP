#include "Zombie.hpp"

/**
 * Stack allocation -> destroyed automatically
 * No return needed!! 
 */
void    randomChump(std::string name)
{
    Zombie zb_stack;

    zb_stack.setName(name);
    zb_stack.announce();
}
