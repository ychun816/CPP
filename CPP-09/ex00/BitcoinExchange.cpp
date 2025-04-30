#include "BitcoinExchange.hpp"

////CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange(){}

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

//LOAD DATA 
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
            
            _data[date] = price;
        }
    }
    file.close();
}

//pase file content
bool BitcoinExchange::parseFileContent(const std::string& line)
{
    size_t pipe = line.find('|');
    if (pipe != std::string::npos) //if not find pipe
    {
        std::string date = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 1);

        //check date
        if (!isValidDate(date))
        {
            printError(DATE);
            std::cerr << date << std::endl;
            return false;
        }
        //check value
        if (!isValidValue(valueStr))
        {
            printError(INVALID_NB);
            return false;
        }

        //convert value str to double
        double value = std::stod(valueStr);
        // printError(INVALID_NB);
        //     return false;

        //check value double range
        if (value < 0)
        {
            printError(NON_POSITIVE);
            return false;
        }
        if (value > 1000)
        {
            printError(LARGE_NB);
            return false;
        }
    }
    return true;
}


//PARSE INPUT FILE
//Apply it to the user input
void BitcoinExchange::parseInputFile(const std::string& fileName)
{
    //open 
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error(ERR_OPEN_FILE);

    //parse/read
    std::string line;
    std::getline(file, line); // Skip header line: "date | value"

    while (std::getline(file, line))
    {
        std::string date;
        double value = 0.0; //init

        //parseFileContent
        if (parseFileContent(line))
            printResult(date, value);

    }
    
    file.close();
}


//static -> check dates
//data content : 2009-01-02,0
//check format first! YYYY-MM-DD!! 
//1 year
//2 month
//3 date
bool BitcoinExchange::isValidDate(const std::string& date)
{
    //format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    //check if all digit
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    //parse checks
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    //basic range check
    if (month < 0 || month > 12 || day < 1 || day > 31)
        return false;
    
    //check month with only 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }

    //check leap year!!
    if (month == 2)
    {
        if (day > 29)
            return false;
        if (day == 29)
        {
            if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) //to count leap year!
                return false;
        }
    }

    return true;
}

//std::stod -> convert str to double
bool BitcoinExchange::isValidValue(const std::string& valueStr)
{    
    try
    {
        double value = std::stod(valueStr);
        if (value >= 0.0 && value <= 1000.0)
            return true;
        return false;
    }
    catch(const std::exception& e)
    {
        return false;
        // std::cerr << e.what() << '\n';
    }

}

//printer
void BitcoinExchange::printError(eError error)
{
    switch (error)
    {
        case OPEN_FILE:
            std::cerr << ERR_OPEN_FILE << std::endl;
            // return 1;
            break;
        case NON_POSITIVE:
            std::cerr << ERR_NON_POSITIVE << std::endl;
            break;
        case DATE:
            std::cerr << ERR_DATE;
            break;
        case LARGE_NB:
            std::cerr << ERR_LARGE_NB << std::endl;
            break;
        case INVALID_NB:
            std::cerr << ERR_NB << std::endl;
            break;
        default:
            std::cerr << "Unknown error." << std::endl;
    }
    // return 1;
}

//PRINT RESULT
void BitcoinExchange::printResult(const std::string& date, double value)
{
    std::cout << date << " => " << value << std::endl;
}