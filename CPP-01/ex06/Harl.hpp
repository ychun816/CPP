#ifndef HARL_HPP
# define HARL_HPP


#include <iostream>
#include <string>
using namespace std;

class Harl
{
    public:
        Harl();
        ~Harl();

        void    filterComplains( std::string level );//decide which function to display according to input
        
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
};

#endif