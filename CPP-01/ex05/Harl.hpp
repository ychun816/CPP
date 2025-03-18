#ifndef HARL_HPP
# define HARL_HPP


#include <iostream>
#include <string>
using namespace std;

//Instead of if/else, use an array of function pointers.
//Learn how to call member functions dynamically.

class Harl
{
    public:
        Harl();//do i need?
        ~Harl();//do i need?

        void    complain( std::string level );//decide which function to display
        
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
};

#endif