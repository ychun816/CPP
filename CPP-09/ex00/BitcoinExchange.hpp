#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <limits>
#include <string>
#include <fstream> // for open file

#define ERR_OPEN_FILE "Error: could not open file." 
#define ERR_NON_POSITIVE "Error: not a positive number."
#define ERR_DATE "Error: bad input => "
#define ERR_LARGE_NB "Error: too large a number."

enum class eError
{
    OPEN_FILE,
    NON_POSITIVE,
    DATE,
    LARGE_NB
};

// template <typename T>
class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;

        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();
        
        ////MEMBER FUNCS
        //getter
        const std::map<std::string, double>& getData() const;

        //open and parse input file
        void loadData(const std::string& filename);
        void parseInputFile(const std::string& fileContent);
        
        //static -> check date & value
        static bool isValidDate(const std::string& date);
        static bool isValidValue(const std::string& value);

        //printer
        int printError(const std::string& error);
        // void printOutcome();

};



#endif

/* NOTES:

        //getter
        const std::map<std::string, double>& getData() const;//avoids returning a copy of the whole map
        //fist const -> return a reference to a const map -> Caller cannot modify the map
        //second const -> the map itself is const -> The function does not change the object’s internal state
        //=> (1) protect your class’s internal data (const reference)
        //=> (2) Ensure the function is safe to call on const objects (function is const)



*/