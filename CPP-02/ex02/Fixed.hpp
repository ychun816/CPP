#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/**
@notes Pre-increment/decrement
- modifies the object and returns a reference to it
- operation happen before returning => return *this as a reference to the current object.
- returning a reference (Fixed&) avoids making a copy, improving performance

@notes Post-increment/decrement
- returns the original value before modifying the object.
- Need to return the previous value => store the current object (temp = *this
*/

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        //contructors: default, int, float
        Fixed();//default
        Fixed(const int intValue);//int constructor 
        Fixed(const float floatValue);//float 
        Fixed(const Fixed& other);//copy contructor
        Fixed &operator=(const Fixed& other);//assignment constructor
        ~Fixed();//destructor

        //convertor
        float toFloat(void) const;
        int toInt(void) const;
        
        //comparison operators: > < >= <= == != 
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        //calculation operators: + - * / 
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
           
        Fixed& operator++();//pre increment ++a
        Fixed operator++();//post increment a++
    
        Fixed& operator--();//pre decrement
        Fixed operator--();//post decrement
    };
    
    //min max funcs
    //min
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    //max
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Output stream overload
    std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 

#endif