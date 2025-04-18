#ifndef SCLARCONVERTER_HPP
#define SCLARCONVERTER_HPP

#include <iostream>
#include <iomanip>
//std::fixed → Show fixed-point notation (like 3.0 instead of 3e+00)
//std::setprecision(n) → Control the number of decimal places
#include <sstream> //std::stringstream ->  treat a string like a stream 


class ScalarConverter
{
    //
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

    public:
        static void convert(const std::string &literal);

        static void printChar(char c);
        static void printInt(int i);
        static void printFloat(float f);
        static void printDouble(double d);

};



#endif 


/* NOTES:

//implicit cast
automatic, safe conversion. E.g., int a = 3.5; → a becomes 3.


//explicit cast 
static_cast: Safe conversion between compatible types.

reinterpret_cast: Bit-level, rarely used (not needed here).

dynamic_cast: For polymorphism (also not needed here).

const_cast: Removes const (not needed here either).

*/

/*

std::stoi() → string to int

std::stof() → string to float

std::stod() → string to double


*/

