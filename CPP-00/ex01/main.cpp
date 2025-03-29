#include "Contact.hpp"
#include "Phonebook.hpp"

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

//display CMDS for HELP
void    display_cmds(std::string arg)
{
    if (arg == "INDEX" || arg == "HELP")
    {
        std::cout << "------- {Phonebook Manual} -------" << std::endl;
        std::cout << "[ADD] : Add contact info" << std::endl;
        std::cout << "[SEARCH] : Search contact info" << std::endl;
        std::cout << "[HELP] : Display all commands" << std::endl;
        std::cout << "[EXIT] : Exit Phonebook" << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }
    else if (arg == "EXIT")
    {
        std::cout << std::endl;
        std::cout << "┈┈୨୧┈┈  Successfully Exit Phonebook  ┈┈୨୧┈┈" << std::endl;
    }
}

/**
Prevent Infinite Loops
//If the user enters EOF (Ctrl+D on Linux/macOS, Ctrl+Z on Windows), the loop breaks
If the user closes the input stream (e.g., by pressing Ctrl+D on Linux/macOS or Ctrl+Z on Windows), 
std::getline(std::cin, line) will fail, and the program might keep running indefinitely unless you check for EOF.
 */
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
        std::getline(std::cin, input);
        if (std::cin.eof())
            break;
        if (input == "EXIT")
        {
            display_cmds("EXIT");
            break;
        }
        else if (input == "ADD")
        {
            Contact newContact;
            if (newContact.createContact())
                phonebook.addContact(newContact);
                // contact.createContact();
            continue;
        }
        else if (input == "HELP")
        {
            display_cmds("HELP");
            continue;
        }
        else if (input == "SEARCH")
        {
            phonebook.displayAllContacts();
            std::cout << "Enter index of contact to view: ";
            std::getline(std::cin, input);
            phonebook.searchContact(input);
        }
        else
        {
            std::cout << "Command Not Found. Type 'HELP' for Command Index." << std::endl;
            continue;
        }
    }
    return (0);
}
