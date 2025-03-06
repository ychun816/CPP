#include <iostream>

using namespace std;

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
    }
    std::cout << std::endl;
    return (0);
}