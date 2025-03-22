#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/* WHAT TO LEARN FRM THIS?
Handle integers and floating-point numbers and allows conversion between them
1. Constructors Overloading
- A constructor that accepts an int and converts it to fixed-point.
- A constructor that accepts a float and converts it to fixed-point.

2. Floating-Point to Fixed-Point Conversion
- Fixed-point numbers are stored as integers, but they represent fractions by shifting bits.
- Conversion formula: fixed-point value=integer value×2 [fractional bits]

3. Fixed-Point to Floating-Point & Integer Conversion
- Function to convert fixed-point back to a floating-point value.
- Function to convert fixed-point back to an integer value.

4. Operator Overloading (<<)
- Overloading operator<< for std::ostream allows us to print Fixed objects directly
*/

class Fixed
{
    private:
        int _value;// Stores the fixed-point number
        static const int _fractionalBits = 8; 
        // Number of fractional bits
        //because it is a compile-time constant and does not require a separate definition in the .cpp file.
    
    public:
        //constructor
        Fixed();//default constructor
        Fixed(const int intValue);//int constructor
        Fixed(const float floatValue);//float constructor
        Fixed(const Fixed& other);//copy constructor
        Fixed& operator=(const Fixed& other);//assign constructor
        ~Fixed();//destructor

        //get set raw bits
        void setRawBits( int const raw );
        int getRawBits( void ) const;

        //converter
        float toFloat( void ) const;
        int toInt( void ) const;
};

//static operator
std::ostream& operator<<(std::ostream& output, const Fixed& fixed); 

#endif