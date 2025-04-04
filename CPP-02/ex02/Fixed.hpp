#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();//default
        Fixed(const int intValue);//int constructor 
        Fixed(const float floatValue);//float 
        Fixed(const Fixed& other);//copy contructor
        Fixed& operator=(const Fixed& other);//assignment operator
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
        
        //increment 
        Fixed& operator++();//pre increment ++a
        Fixed operator++(int);//post increment a++
    
        //decrement
        Fixed& operator--();//pre decrement
        Fixed operator--(int);//post decrement

        //min max funcs
        //min
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        //max
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
    };
    
    // Output stream overload
    std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif