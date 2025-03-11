#include "Zombie.hpp"

// Stack allocation!
// No return needed, zb_stack is destroyed automatically
void    randomChump(std::string name)
{
    Zombie zb_stack;

    zb_stack.setName(name);
    zb_stack.announce();
    // setName(name);
    // announce();
}
