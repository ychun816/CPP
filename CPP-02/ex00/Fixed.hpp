#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();//A default constructor 
        //A copy constructor
        //A copy assignment operator overload
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
    
    private:
        int fixed_point;//An integer to store the fixed-point number value
        int const nb_fractional_bits;//A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8

}


#endif