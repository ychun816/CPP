#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/**
 * @note  static const int fractionalBits = 8;
 * A static constant integer to store the number of fractional bits.
 * Its value will always be the integer literal 8
 */
class Fixed
{
    private:
        int _value;
        static const int fractionalBits = 8;

    public:
        Fixed();//default
        Fixed(const Fixed& other);//copy constructor
        Fixed& operator=(const Fixed& other);//assign
        ~Fixed();//destructor

        //MEMBER FUNCS
        int getRawBits( void ) const;//get raw int value
        void setRawBits( int const raw );//set raw int value
};

#endif