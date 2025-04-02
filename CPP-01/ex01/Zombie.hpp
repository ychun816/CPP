#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

/** STEPS:
 * Allocate memory for N zombies in one operation
 * Initialize each zombie with given name
 * Return a pointer to the first zombie
*/

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);

        void setName(std::string name);
        void announce( void );

    private:
        std::string _name;
};

Zombie*    zombieHorde( int N, std::string name );

#endif