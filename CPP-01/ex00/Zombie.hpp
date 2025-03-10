#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        Zombie* newZombie( std::string name );//creates a zombie, name it, and return it so you can use it outside of the function scope.
        void announce( void );//makes zombie speak
        void randomChump( std::string name );//creates a zombie, name it, and the zombie announces itself.

    private:
        std::string _name;
};


#endif