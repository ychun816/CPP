#ifndef SCLARCONVERTER_HPP
#define SCLARCONVERTER_HPP

#include <iostream>
#include <cctype>  //std::isdigit(c) //std::isprint(c) //std::isalpha(c)
#include <limits>  //min/max values of numeric types
#include <iomanip> //std::fixed //std::setprecision(n)
#include <cmath>   //std::isnan(value) //std::isinf(value)
#include <cstdlib> //std::atoi //std::atof //std::stod()

//utility class -> set constructor&destructor private -> prevent instantiation
//static methods -> set member funcs "static" -> access without instantiation
class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

        enum Type
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            PSEUDO_LITERAL,
            INVALID
        };

    public:
        ////convert
        static Type checkType(const std::string& input);
        static void convert(const std::string& input);

        ////parsing & check input
        static bool isChar(const std::string& input);
        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);
        static bool isPseudoLiteral(const std::string& input);
        static void handleSpecialCase(const std::string& input);
        
        ////print value
        static void printChar(char charValue);
        static void printInt(int intValue);
        static void printFloat(float floatValue);
        static void printDouble(double doubleValue);
        
        static void printConversionChar(char c);
        static void printConversionInt(int i);
        static void printConversionFloat(float f);
        static void printConversionDouble(double d);
};

#endif 


/* NOTES:

//implicit cast
automatic, safe conversion. E.g., int a = 3.5; → a becomes 3.

//explicit cast 
- static_cast: Safe conversion between compatible types.
- reinterpret_cast: Bit-level, rarely used (not needed here).
- dynamic_cast: For polymorphism (also not needed here).
- const_cast: Removes const (not needed here either).


//"static" member funcs in a class
-> A static member function belongs to the class itself, not any instance. 
-> It can be called without creating an object and cannot access non-static members.


// Pseudo Literal Heirachy : char → int → float → double (When mixing types, C++ will promote to the larger or more precise type 
// (e.g., char + float → float, int + double → double))
// double : -inf / +inf / nan
// float : -inff /  +inff / nanf


//#include <cstdlib>
std::stoi() → string to int
std::stof() → string to float
std::stod() → string to double

//#include <iomanip>
std::fixed → Show fixed-point notation (like 3.0 instead of 3e+00)
std::setprecision(n) → Control the number of decimal places

//#include <cmath>
std::isnan(value) → Checks if a number is NaN (Not a Number)
std::isinf(value) → Checks for infinity

*/