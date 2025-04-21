#include "ScalarConverter.hpp"

//1 string parsing & check
//2 convert


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