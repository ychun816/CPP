#include "ScalarConverter.hpp"

////CONTRUCTOR & DESTRUCTOR -> NO NEED IMPLEMENTATION
// Remove this — not needed
// ScalarConverter::ScalarConverter() {}
// ScalarConverter::ScalarConverter(const ScalarConverter&) {}
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
// ScalarConverter::~ScalarConverter() {}

////MEMBER FUNCS
//convert 
static void convert(const std::string& input)
{

}

//check input
//.length() / std::isdidgit() / std::isprint()
static bool isChar(const std::string& input)
{
    return (input.length() == 1 && std::isprint(input[0]) && std::isdigit(input[0]));
}

//like atoi precheck
static bool isInt(const std::string& input)
{
    if (input.length() == 1 && !std::isdigit(input[0]))
        return false;
    for (int i = 0; i < input.length(); i++)
    {
        if (i == 0 && (input[i] == '-' || input[i] == '+'))
                continue;
        return false;
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string& input)
{
    bool hasDecimal = false;
    
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return true;
    //check first sign
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    //check digits after sign
    for (; i < input.length(); i++) //;-> as i is declared&init before 
    {
        if (std::isdigit(input[i]))
            continue;
        //check point . -> has to be f after 
        if (input[i] == '.')
        {
            if (hasDecimal)
            {
                return false;
                hasDecimal = true;
            }
            else if (input[i] == 'f')
            {
                if (i == input.length() - 1 && hasDecimal)//f at the end & has decimal
                    return false;
            }
            else if (std::isdigit(input[i]))
                    return false;
        }
    }
    return false;//f no find in the end
}

//1 Handle pseudo-literals first: special double values
//2 check first sign -> Skip '+' or '-'
//3 Flag to ensure there's one decimal point
//4 Loop through characters in the input :
// // If there's more than one '.', it's invalid

static bool isDouble(const std::string& input)
{
    bool hasDecimal = false;
    
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return true;
   
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
            i++;
    for (; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true; // first '.' is allowed
        }
        else if (std::isdigit(input[i]))// Any non-digit (and not '.') character is invalid
            return false;
    }
    return true; // If reach here, it's a valid double
}

static bool isPseudoLiteral(const std::string& input)
{
    return input == "nan" || input == "nanf" ||
           input == "+inf" || input == "+inff" ||
           input == "-inf" || input == "-inff";
}


////print value
static void printInt(int intValue)
{
    std::cout << "Int: " << intValue << std::endl;
}

static void printChar(char charValue)
{
    if (isprint(charValue))
        std::cout << "Char: "<< charValue << std::endl;
    else
        std::cout << "Char Error: Non displayable" << std::endl;
}

//std::setprecision(1)
//-> manipulator from the <iomanip> header in C++
//-> set the number of digits to be displayed after the decimal point for floating-point output — but only when used with std::fixed.

//oss is a variable of type std::ostringstream — a stream that works like std::cout, 
//but instead of printing to the console, it stores the output in a string buffer.
//Think of it as: a string version of std::cout.

static void printFloat(float floatValue)
{
    std::cout << "Float: ";
    std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
}

static void printDouble(double doubleValue)
{
    std::cout << "Double: ";
    std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

//print conversions
static void printConversionInt(int i)
{}
static void printConversionFloat(float f)
{}
static void printConversionDouble(double d)
{}


