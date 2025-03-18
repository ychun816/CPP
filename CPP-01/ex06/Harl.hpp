#ifndef HARL_HPP
# define HARL_HPP


#include <iostream>
#include <string>
using namespace std;

class Harl
{
    public:
        Harl();//do i need?
        ~Harl();//do i need?

        void    filterComplains( std::string level );//decide which function to display
        
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
};

#endif