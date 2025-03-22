#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/**
@notes



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
    min();
    max(const int a, const int b);

    // Output stream overload
    std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 


#endif