#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

#define ERR_OPEN_FILE "Error: could not open file." 
#define ERR_NON_POSITIVE "Error: not a positive number."
#define ERR_DATE "Error: bad input => "
#define ERR_LARGE_NB "Error: too large a number."

template <typename T>
class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        ////MEMBER FUNCS
        void openFile(const std::string& filename);
        void parseFIle(const std::string& fileContent);
    
        //static in cpp -> check date
        bool checkDate(const std::string& date); //should i make static in cpp?
        //static in cpp -> check value
        bool checkValue(const std::string& value); //should i make static in cpp?

        void printOutcome();
        void printError(const std::string& error);

};



#endif