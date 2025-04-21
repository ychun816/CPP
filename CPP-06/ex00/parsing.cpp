#include "ScalarConverter.hpp"

////check input
//.length() / std::isdidgit() / std::isprint()
bool ScalarConverter::isChar(const std::string& input)
{
    return (input.length() == 1 && std::isprint(input[0]) && std::isdigit(input[0]));
}

//like atoi precheck
bool ScalarConverter::isInt(const std::string& input)
{
    if (input.length() == 1 && !std::isdigit(input[0]))
        return false;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (i == 0 && (input[i] == '-' || input[i] == '+'))
                continue;
        return false;
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& input)
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
bool ScalarConverter::isDouble(const std::string& input)
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

//check special case -> psuedo literals
bool ScalarConverter::isPseudoLiteral(const std::string& input)
{
    return input == "nan" || input == "nanf" ||
           input == "+inf" || input == "+inff" ||
           input == "-inf" || input == "-inff";
}

//handle special case
//Pseudo-literals like "nan" cannot be converted to char or int, so we print "impossible"
//If the input is a NaN, either as float (nanf) or double (nan)
void ScalarConverter::handleSpecialCase(const std::string& input)
{
    std::cout << "Char: impossible" << std::endl;
    std::cout << "Int: impossible" << std::endl;

    if (input == "nanf" || input == "nan")
    {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    else if (input == "+inff" || input == "+inff")//positive infinity
    {
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (input == "-inff" || input == "-inff")//negative infinity
    {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else
    {
        std::cout << "Float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl; 
    }
}