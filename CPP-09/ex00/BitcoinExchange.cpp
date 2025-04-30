#include "BitcoinExchange.hpp"

////CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange() : _data(0.00){}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _data(src._data){}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        _data = src._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}



////MEMBER FUNCS
//getter
const std::map<std::string, double>& BitcoinExchange::getData() const
{
    return _data;
}

//open and parse input file
//Open the exchange rate CSV file
//std::istringstream : Creates an input string stream from the line / extract the two fields (date, rateStr) from that line
//std::string::npos : normally used to indicate that a string was not found
void BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error(ERR_OPEN_FILE);
    
    std::string line;
    getline(file, line); // Skip header line: "date,exchange_rate"!!

    while (std::getline(file, line))//Reads the file line by line //Each line is stored in the line string
    {
        size_t comma = line.find(','); //Find the position of the comma in the line
        if (comma != std::string::npos)
        {
            std::string date = line.substr(0, comma); //extract frm 0 to comma
            if (!isValidDate(date))
                throw std::runtime_error(ERR_DATE);

            std::string priceStr = line.substr(comma + 1);//extract frm after comma to end
            double price = std::stod(priceStr); //Convert the string to a double
            if (!isValidValue(priceStr))
                throw std::runtime_error(ERR_LARGE_NB);
        }
    }
}

void BitcoinExchange::parseInputFile(const std::string& fileContent)
{

}

//static -> check dates
//data content : 2009-01-02,0
//check format first! YYYY-MM-DD!! 
//1 year
//2 month
//3 date
static bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    //year 
    int year = std::stoi(date.substr(0, 4));
    if (year < 2009 || year > 2023)
        return false;
    //month
    int month = std::stoi(date.substr(5, 2));
    if (! (month >= 1 && month <= 12))
        return false;
    //date
    int day = std::stoi(date.substr(8, 2));
    if (!(day >= 1 && day <= 31)) //// handle leap years!! 
        return false;
}

//std::stod -> convert str to double
static bool BitcoinExchange::isValidValue(const std::string& valueStr)
{
    double value = std::stod(valueStr);
    if (value < 0)
        return false;
    if (value > std::numeric_limits<double>::max())
        return false;
    return true;
}

//printer
int BitcoinExchange::printError(const std::string& error)
{
    switch (error)
    {
        case eError::OPEN_FILE:
            std::cerr << ERR_OPEN_FILE << std::endl;
            // return 1;
            break;
        case eError::NON_POSITIVE:
            std::cerr << ERR_NON_POSITIVE << std::endl;
            break;
        case eError::DATE:
            std::cerr << ERR_DATE << std::endl;
            break;
        case eError::LARGE_NB:
            std::cerr << ERR_LARGE_NB << std::endl;
            break;
        default:
            std::cerr << "Unknown error." << std::endl;
    }
    return 1;
}
