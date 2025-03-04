#include "Contact.hpp"

//constructor
Contact::Contact(void)
{
}

//decontructor
Contact::~Contact(void)
{

}

// 

//to display the input stored in the variables
// void    displayContact(void)
// {
//     std::cout << "📞 Contact Info:\n";
//     std::cout << "First Name: " << _firstName << std::endl;
//     std::cout << "Last Name: " << _lasttName << std::endl;
//     std::cout << "Phone Number: " << _phoneNumber << std::endl;
//     std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
// }

//set contact value
void    Contact::setFirstname(std::string str)
{
	this->_firstName = str;
	return ;
}

void    setLastname(std::string str)
{
	this->_lastName = str;
	return ;
}

void    setNickname(std::string str)
{
    this->_nickName = str;
    return ;
}

void    setPhoneNr(std::string str)
{
    this->_phoneNr = str;
    return ;
}

void    setSecret(std::string str)
{
    this->_secret = str;
    return ;
}


// Getter methods to return contact details
void    getFirstname(void) const
{
    
}

void    getLastname(void) const;

void    getNickname(void) const;

void    getPhoneNr(void) const;

void    getSecret(void) const;


// Function to take user input for contact details
// void    Contact::setContact(void)
// {
//    //first name
//     std::cout << "Enter First Name: ";
//     std::getline(std::cin, _firstName);
//     while (_firstName.empty()) 
//     {
//         std::cout << "Field cannot be empty!! Enter First Name AGAIN: ";
//         std::getline(std::cin, _firstName);
//     }

//     //last name
//     std::cout << "Enter Last Name: ";
//     std::getline(std::cin, _lastName);
//     while (_lastName.empty())
//     {
//         std::cout << "Field cannot be empty!! Enter First Name AGAIN: ";
//         std::getline(std::cin, _lastName);
//     }

//     //nickname
//     std::cout << "Enter Nick Name: ";
//     std::getline(std::cin, _nickName);
//     while (_lastName.empty())
//     {
//         std::cout << "Field cannot be empty!! Enter Nick Name AGAIN: ";
//         std::getline(std::cin, _nickName);
//     }

//     //phone number
//     std::cout << "Enter Phone Number: ";
//     std::getline(std::cin, _phoneNr);//number can also use this?
//     while (_phoneNumber.empty())
//     {
//         std::cout << "Field cannot be empty!! Enter Phone Number AGAIN: ";
//         std::getline(std::cin, _phoneNr);
//     }

//     //dark secret
//     std::cout << "You Darket Secret?: ";
//     std::getline(std::cin, _secret);
//     while (_secret.empty())
//     {
//         std::cout << "Field cannot be empty!! Enter AGAIN: ";
//         std::getline(std::cin, secret);
//     }
//     std::cout << "✅ CONTACT INFO SAVED!\n";
// }