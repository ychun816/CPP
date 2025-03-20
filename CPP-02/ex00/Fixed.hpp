#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _value;//An integer to store the fixed-point number value
        static const int fractionalBits = 8;//A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8

    public:
        //A default constructor 
        Fixed();//_value(0);
        
        //A copy constructor
        Fixed(const Fixed& other);

        //A copy assignment operator overload
        Fixed& operator=(const Fixed& other);

        // Destructor
        ~Fixed();

        //get raw int value
        int getRawBits( void ) const;

        //set raw int value
        void setRawBits( int const raw );

};

#endif


/*
Implement Orthodox Canonical Form: 
- Default constructor
- Copy constructor
- Copy assignment operator (operator=)
- Destructor

*/