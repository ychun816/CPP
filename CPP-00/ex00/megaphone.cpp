#include <iostream>

// using namespace std;

/**
 * 1. loop through the args
 * 2. get len of each str -> to upper 
 */
int main(int ac, char *av[])
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        for (int j = 0; j < str.length(); j++)
            std::cout << (char)std::toupper(str[j]);
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}