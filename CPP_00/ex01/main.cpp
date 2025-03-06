
#include "Contact.hpp"
#include "Phonebook.hpp"

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
    std::cout << "┈┈୨୧┈┈ 🧸🍒 Welcome to Phonebook!! 🍒🧸 ┈┈୨୧┈┈" << std::endl;
    std::cout << std::endl;
}
//display commands for HELP
void    display_cmds(std::string arg)//string args
{
    if (arg == "INDEX" || arg == "HELP")
    {
        std::cout << "[ADD] : Add contact info" << std::endl;
        std::cout << "[SEARCH] : Search contact info" << std::endl;
        std::cout << "[HELP] : Display all commands" << std::endl;
        std::cout << "[EXIT] : Exit Phonebook" << std::endl;
        std::cout << std::endl;
    }
    else if (arg == "EXIT")
    {
        std::cout << std::endl;
        std::cout << "┈┈୨୧┈┈ Successfully Exit Phonebook ┈┈୨୧┈┈" << std::endl;
    }
}

//1. Prevent Infinite Loops
//If the user closes the input stream (e.g., by pressing Ctrl+D on Linux/macOS or Ctrl+Z on Windows), 
//std::getline(std::cin, line) will fail, and the program might keep running indefinitely unless you check for EOF.

int main()
{
    std::string input;
    Contact contact;
    Phonebook phonebook;

    welcome_msg();
    display_cmds("INDEX");
    while(true)
    {
        std::cout << "𓀎 Please Enter a Command 𓀎 ➔ ";
        //prevent infinite loop
        std::getline(std::cin, input);
        if (std::cin.eof())//If the user enters EOF (Ctrl+D on Linux/macOS, Ctrl+Z on Windows), the loop breaks
            break ;
        if (input == "ADD")
        {
            contact.createContact();
            display_cmds("EXIT");
        }
        else if (input == "HELP")
            display_cmds("HELP");
        else if (input == "SEARCH")///
            phonebook.displayAllContacts();
        if (input == "EXIT")
            display_cmds("EXIT");
        std::cout << std::endl;
        return (0);
    }
}

// •┈┈┈┈┈┈୨୧┈┈┈┈┈┈•