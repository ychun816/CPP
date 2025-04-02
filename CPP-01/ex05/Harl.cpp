#include "Harl.hpp"

//CONSTUCTOR & DESTRUCTOR
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

//PUBLIC FUNCS
/** COMPLAIN()
 * A function pointer stores the address of a function so it can be called dynamically:
 * - Create a array of string
 * - Like a index to print different msg
 * - Create a function pointer array
 * 
 * 1. Put '&' for the address for the private helper funcs 
 * 2. Loop to print different msg
 * 3. Find to call the corresponding function
 * -> If the loop completes, it means the level was invalid
 *  @note (this->*funcPtr[i])();
 * -> Call the member function pointed to by funcPtr[i] on the current instance (this) of the class Harl.
 */
void Harl::complain( std::string cmd)
{
    std::string cmds[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for (int i = 0; i < 4; i++)
    {
        if (cmd == cmds[i])
        {
            (this->*funcPtr[i])();
            return;
        }
    }
    std::cout << "Invalid Command: " << cmd << std::endl;
}