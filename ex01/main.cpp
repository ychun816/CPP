
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
*/
//getline-> arg= ADD, SEARCH, HELP
//ADD ->setcntact
//SEARCH -> displaycontact
//HELP -> print commands

//welcome msg
void    welcome_msg()
{
    std::cout << "Welcome to Phonebook!!" << std::endl;
}
//display commands for HELP
void    display_command(std::string arg)//string args
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

int main()
{
    std::string input;
    // Phonebook phonebook;
    //Contact newContact;

    welcome_msg();
    while(true)
    {
        if (getline(input) == "ADD")
            //show contact
        if (getline(input) == "SEARCH")
            //do search
        if (getline(input) == "HELP")
            display_command("HELP");
        display_command("HELP");
    }
    // newContact.setContact();//access to contact class
    // newContact.displayContact();//display contact info

}