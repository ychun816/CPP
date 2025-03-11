#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        void announce( void );//makes zombie speak
        
    private:
        std::string _name;
        
};
    
Zombie* newZombie( std::string name );//creates a zombie, name it, and return it so you can use it outside of the function scope.
void randomChump( std::string name );//creates a zombie, name it, and the zombie announces itself.

#endif