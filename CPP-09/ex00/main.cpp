#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }    
    
    try 
    {
        BitcoinExchange btc;
        btc.loadData("data.csv");
        btc.parseInputFile(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }     

    return 0;
}
