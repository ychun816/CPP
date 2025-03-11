#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>


/** STEPS:
Let me walk you through the correct approach for implementing the zombieHorde function. Your general idea is on the right track, but there are some key elements we need to adjust.
The requirement is to allocate N zombies in a single allocation, not N separate allocations. Let's break down the correct approach:

Your first point is correct: we need a Zombie class with a private _name variable.
Your second point about including setName and newZombie functions is also good, but we'll use a different approach for the horde.
For the zombieHorde function, your approach would create N separate allocations, which isn't what we want. Instead, we need to:

Allocate memory for N zombies in one operation
Initialize each zombie with the given name
Return a pointer to the first zombie

*/


class zombies
{
    public:
        Zombie();
        ~Zombie();

        void setName(std::string name);
        void announce( void );

    private:
        _name;

}

Zombie*    zombieHorde( int N, std::string name );

#endif