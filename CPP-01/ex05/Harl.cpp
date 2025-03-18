#include "Harl.hpp"
using namespace std;

Harl::Harl(){}
Harl::~Harl(){}

//private helper funcs
void Harl::debug( void )
{
    cout << "[DEBUG]" << endl;
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << endl;
}

void Harl::info( void )
{
    cout << "[INFO]" << endl;
    cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning( void )
{
    cout << "[WARNING]" << endl;
    cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << endl;
}

void Harl::error( void )
{
    cout << "[ERROR]" << endl;
    cout << "This is unacceptable! I want to speak to the manager now." << endl;
}


//like a index to print different msg
//create a array of string
//create a function pointer array
//A function pointer stores the address of a function so it can be called dynamically
void Harl::complain( std::string level)
{
    string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //put & for the address 
    
    //loop to print different msg
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*funcPtr[i])();// Calls the corresponding function ???
            return;
        }
    }
    // If the loop completes, it means the level was invalid.
    cout << "Invalid level: " << level << endl;
}

/* 
Explanation of (this->*funcPtr[i])();:

funcPtr[i]: This accesses the i-th element of the funcPtr array, which is a pointer to a member function of the Harl class (e.g., &Harl::debug, &Harl::info, etc.).

this->*: This syntax is used to call a member function through a pointer to member function. this is a pointer to the current object of type Harl. * is used to dereference the member function pointer and access the member function.

this->* is necessary because you are accessing a member function of the object (the instance of Harl), not a regular function. It tells the compiler that you want to call a member function of the object pointed to by this.

(): After dereferencing the pointer to the member function, you add () to invoke the function.

Putting it all together:
(this->*funcPtr[i])(); means "call the member function pointed to by funcPtr[i] on the current instance (this) of the class Harl."

*/