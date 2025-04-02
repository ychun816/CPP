#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

/**
 * @note
 * Zombie* newZombie( std::string name );
 * -> create a zombie, name it
 * -> return it => can use it outside of the function scope
 * 
 * void randomChump( std::string name ); 
 * -> create a zombie, name it
 * -> the zombie announces itself
 */
class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        void announce( void );
        
    private:
        std::string _name;
        
};
    
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif