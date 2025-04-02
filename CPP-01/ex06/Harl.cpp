#include "Harl.hpp"

//CONSTRUCTOR & DESTRUCTOR
Harl::Harl(){}
Harl::~Harl(){}

//PRIVATE FUNCS
void Harl::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

//PULIC FUNCS
/**
 * @note
 * switch statement is used to determine which log level was matched
 * create index -> essentially help map the string input (level) to a specific function call (in this case, one of the functions in the funcPtr[] array).
 * int index = -1; // Initialize the index variable with -1 (default invalid value -> indicate no match)
*/
void Harl::filterComplains( std::string cmd)
{
    string cmds[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 

    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (cmd == cmds[i])
        {
            index = i;    
            break;// Exit loop once match is found
        }
    }

    switch (index)
    {
        case 0://DEBUG
            (this->*funcPtr[0])();
            // break; // Stop here if index == 0
        case 1://INFO
            (this->*funcPtr[1])();
            // break; // Stop here if index == 1
        case 2://WARNING
            (this->*funcPtr[2])();
            // break;
        case 3://ERROR
            (this->*funcPtr[3])();
        break;
        default:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
    }
}


/* GENERAL SYNTAX FOR SWITCH
switch (expression) {
    case value1:
        // Code to execute if expression == value1
        break;  // Optional, but prevents fall-through
    case value2:
        // Code to execute if expression == value2
        break;
    case value3:
        // Code to execute if expression == value3
        break;
    ...
    default:
        // Code to execute if no case matches
}
*/