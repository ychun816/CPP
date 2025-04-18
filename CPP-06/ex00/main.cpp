#include "ScalarConverter.hpp"

//string parsing & check
//convert
//print

//check len & digit
//.length()
//.isdigit
//note: true (1) / false(0)
static bool isCharLiteral(const std::string& arg)
{
    if (arg.length() == 1 && std::isdigit(arg[0]) == false)
        return true;//1!!!
}


//check if arg is a special literal (nan), +inf, -inf, "+inff , inff
static bool isSpecialLiteral(const std::string &arg)
{
    if (arg == "nan" || arg == "+inf" || arg == "-inf" || arg == "nanf" || arg == "+inff" || arg == "-inff")
        return true;//1!!!
    return false;
}





int main(int ac, char *av[])
{
    //1 check ac 
    if (ac != 2)
    {
        std::cerr << "Error! Usage: ./Convert <literal>" << std::endl;
        return 1;
    }

    //2 check arg 
    //check arg literal 
    //special literal (nan), +inf, -inf, "+inff , inff
    // if ( !isCharLiteral(av[1]) || !isSpecialLiteral(av[1]))//false(0)   -> should be in loop? 
    // {
    //     std::cerr << "Error: Invalid argument" << std::endl;
    //     return 1;
    // }
    for (int i = 1; i < ac; i++)
    {
        if (isCharLiteral(av[i]))
        {
            std::cout << "char: " << av[i] << std::endl;
        }
        else if (isSpecialLiteral(av[i]))
        {
            std::cout << "special literal: " << av[i] << std::endl;
        }
        else
        {
            std::cerr << "Error: Invalid argument" << std::endl;
            return 1;
        }
    }

    //3 convert 
    ScalarConverter::convert(av[1]);
    return 0;
}