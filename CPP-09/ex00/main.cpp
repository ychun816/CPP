#include "BitcoinExchange.hpp"


int main(int ac, char *av[])
{
    if (ac != 2)
        BitcoinExchange::printError(ERR_OPEN_FILE);
        
    try 
    {
        BitcoinExchange btc;
        btc.loadData(av[1]);
        btc.parseInputFile(av[1]);

    }
    catch (const std::exception& e)
    {
        std::err << e.what() << std::endl;
        return 1;
    }     

    return 0;
}