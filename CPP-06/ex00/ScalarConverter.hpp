#ifndef SCLARCONVERTER_HPP
#define SCLARCONVERTER_HPP

#include <iostream>
#include <iomanip>//std::fixed → Show fixed-point notation (like 3.0 instead of 3e+00)//std::setprecision(n) → Control the number of decimal places
#include <limits> //Get the min/max values of numeric types
#include <cmath> //Math functions and special values//std::isnan(value) → Checks if a number is NaN (Not a Number)//std::isinf(value) → Checks for infinity
#include <cctype>//std::isdigit(c) //std::isprint(c) //std::isalpha(c)
#include <limits>


//constructor & desturctor made private -> declare only, no implementation
class ScalarConverter
{
    //make private -> Prevent the class from being instantiated
    private:
        ScalarConverter();//declared only, not defined
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

    public:
        //convert
        static void convert(std::string const& input);
        
        //check input
        static bool isChar(const std::string& input);
        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);
        static bool isPseudoLiteral(const std::string& input);
        
        //print value
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);

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

/*
Convert using static_cast

*/
