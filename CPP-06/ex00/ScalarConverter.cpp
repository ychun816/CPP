#include "ScalarConverter.hpp"

/* ////CONTRUCTOR & DESTRUCTOR -> NO NEED IMPLEMENTATION OR MAKE PRIVATE
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
*/

////MEMBER FUNCS
////print value
void ScalarConverter::printChar(char charValue)
{
    if (isprint(charValue))
        std::cout << "Char: "<< charValue << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;
}
void ScalarConverter::printInt(int intValue)
{
    std::cout << "Int: " << intValue << std::endl;
}

/** print floate & double  
 * @note std::setprecision(1)
 * -> set the number of digits to be displayed after the decimal point for floating-point output — but only when used with std::fixed.
 */
void ScalarConverter::printFloat(float floatValue)
{
    std::cout << "Float: ";
    std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
}

void ScalarConverter::printDouble(double doubleValue)
{
    std::cout << "Double: ";
    std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

////prit conversion value
void ScalarConverter::printConversionChar(char c)
{
    printChar(c);
    printInt(static_cast<char>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::printConversionInt(int i)
{
    printChar(static_cast<char>(i));
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::printConversionFloat(float f)
{
    printChar(static_cast<char>(f));
    printInt(static_cast<int>(f));
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::printConversionDouble(double d)
{
    printChar(static_cast<char>(d));
    printInt(static_cast<int>(d));
    printFloat(static_cast<float>(d));
    printDouble(d);
}

//checkType
ScalarConverter::Type ScalarConverter::checkType(const std::string& input)
{
    if (isPseudoLiteral(input))
        return PSEUDO_LITERAL;
    else if (isChar(input))
        return CHAR;
    else if (isInt(input))
        return INT;
    else if (isFloat(input))
        return FLOAT;
    else if (isDouble(input))
        return DOUBLE;
    else
        return INVALID;
}

//covert
void ScalarConverter::convert(const std::string& input)
{
    Type inputType = checkType(input);

    switch(inputType)
    {
        case CHAR:
            printConversionChar(static_cast<char>(input[0]));
            break;
        case INT:
            printConversionInt(std::atoi(input.c_str()));
            break;
        case FLOAT:
            printConversionFloat(static_cast<float>(std::atof(input.c_str())));
            break;
        case DOUBLE:
            printConversionDouble(std::atof(input.c_str()));
            break;
        case PSEUDO_LITERAL:
            handleSpecialCase(input);
            break;
        case INVALID:
            std::cerr << "char: impossible" << std::endl;
            std::cerr << "int: impossible" << std::endl;
            std::cerr << "float: impossible" << std::endl;
            std::cerr << "double: impossible" << std::endl;
            break;
    }
}