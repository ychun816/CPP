
#include "Contact.hpp"

// #include "Phonebook.hpp"
// #include <iostream>  // For std::cout, std::cin
// #include <string>    // For std::string
// #include <iomanip>   // For formatted table output

/* Steps for implement
1. set up Conatct class(like structure):
- init string variable
- set functions in class
2. set up Phonebook class

//getline-> arg= ADD, SEARCH, HELP
//ADD ->setcntact
//SEARCH -> displaycontact
//HELP -> print commands
*/

//welcome msg
void    welcome_msg()
{
    std::cout << "Welcome to Phonebook!!" << std::endl;
}
//display commands for HELP
void    display_cmds(std::string arg)//string args
{
    if (arg == "HELP")
    {
        std::cout << "[ADD] : Add contact info" << std::endl;
        std::cout << "[SEARCH] : Search contact info" << std::endl;
        std::cout << "[HELP] : Display all commands" << std::endl;
        std::cout << "[EXIT] : Exit Phonebook" << std::endl;
    }
    else if (arg == "EXIT")
        std::cout << "[EXIT] : Exit Phonebook" << std::endl;
}

//1. Prevent Infinite Loops
//If the user closes the input stream (e.g., by pressing Ctrl+D on Linux/macOS or Ctrl+Z on Windows), 
//std::getline(std::cin, line) will fail, and the program might keep running indefinitely unless you check for EOF.

int main()
{
    std::string input;
    // Phonebook phonebook;
    //Contact newContact; ??

    welcome_msg();
    display_cmds("HELP");
    while(true)
    {
        std::cout << "Please Enter a Command >";
        //prevent infinite loop
        std::getline(std::cin, input);
        if (std::cin.eof())//If the user enters EOF (Ctrl+D on Linux/macOS, Ctrl+Z on Windows), the loop breaks
            break ;
        if (input == "ADD")
            //show contact -> book
        if (input == "SEARCH")
            //do search -> book 
        if (input == "HELP")
            display_cmds("HELP");
        if (input == "EXIT")
            display_cmds("EXIT");
        std::cout << std::endl;
        return (0);
    }
    // newContact.setContact();//access to contact class
    // newContact.displayContact();//display contact info
}