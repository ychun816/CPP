#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

/** Learn how to call member functions dynamically. */
class Harl
{
    public:
        Harl();
        ~Harl();

        void    complain( std::string level );//Decide which function to display
        
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
};

#endif