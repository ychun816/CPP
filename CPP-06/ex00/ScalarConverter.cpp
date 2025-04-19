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

static bool isDouble(const std::string& input)
{
    
}

static bool isPseudoLiteral(const std::string& input)
{
    return input == "nan" || input == "nanf" ||
           input == "+inf" || input == "+inff" ||
           input == "-inf" || input == "-inff";
}


////print value
static void printChar(double value)
{
    std::cout << "Char: ";
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

}

static void printInt(double value)
{
    std::cout << "Int: ";
    std::cout << "'" << static_cast<int>(value) << "'" << std::endl;

}

static void printFloat(double value)
{
    std::cout << "Float: ";
    std::cout << "'" << static_cast<float>(value) << "'" << std::endl;

}

static void printDouble(double value)
{
    std::cout << "Double: ";
    std::cout << "'" << static_cast<double>(value) << "'" << std::endl;
}