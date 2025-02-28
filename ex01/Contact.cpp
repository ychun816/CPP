#include "Contact.hpp"

//contact struct varaible to hold the user inputs
Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNr = "";
    secret = "";
}

// Function to take user input for contact details
Contact::void setContact()
{
   //first name
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    while (firstName.empty()) 
    {
        std::cout << "Field cannot be empty!! Enter First Name AGAIN: ";
        std::getline(std::cin, firstName);
    }
    //last name
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, firstName);
    while (lastName.empty())
    {
        std::cout << "Field cannot be empty!! Enter First Name AGAIN: ";
        std::getline(std::cin, lastName);
    }
    //nickname
    std::cout << "Enter Nick Name: ";
    std::getline(std::cin, nickName);
    while (lastName.empty())
    {
        std::cout << "Field cannot be empty!! Enter Nick Name AGAIN: ";
        std::getline(std::cin, nickName);
    }
    //phone number
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNr);//number can also use this?
    while (phoneNumber.empty())
    {
        std::cout << "Field cannot be empty!! Enter Phone Number AGAIN: ";
        std::getline(std::cin, phoneNr);
    }
    //dark secret
    std::cout << "You Darket Secret?: "
    std::getline(std::cin, secret);
    while (secret.empty())
    {
        std::cout << "Field cannot be empty!! Enter AGAIN: ";
        std::getline(std::cin, secret);
    }
    std::cout << "✅ CONTACT INFO SAVED!\n";
}

//to display the input stored in the variables
Contact::void displayContact() const
{
    std::cout << "📞 Contact Info:\n";
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lasttName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}