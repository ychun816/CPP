#include "Contact.hpp"

//constructor
Contact::Contact(void)
{
}

//decontructor
Contact::~Contact(void)
{

}

//set contact value
void   Contact::setFirstname(std::string str)
{
	this->_firstName = str;
	return ;
}

void    Contact::setLastname(std::string str)
{
	this->_lastName = str;
	return ;
}

void    Contact::setNickname(std::string str)
{
    this->_nickName = str;
    return ;
}

void    Contact::setPhoneNr(std::string str)
{
    this->_phoneNr = str;
    return ;
}

void    Contact::setSecret(std::string str)
{
    this->_secret = str;
    return ;
}

//create contact

/** check is number
 * Loop in str to check if is nbr
 * If find nono-nbr character -> return false; otherwise, return true
*/
bool check_is_nbr(std::string nbr)
{

    for(size_t i = 0; i < nbr.length(); i++)
        if (std::isdigit(nbr[i]) == false)
            return false ;
    return true ;
}    

/** trim space
 * (1) Erase leading spaces (frm str start)
 * (2) Erase trailing spaces (frm str end)
 * 
 * @note std::string& str: the parameter str is passed by reference (&)
 * @note [function] str.erase(start_position, length);
 * Find the first character in a string that is NOT part of a given set of characters
 * @note str.erase(str.find_first_not_of(' ') + 1);
 * Returns the index of the last non-space character.
 * +1: We add 1 because we want to remove the space after the last non-space character, which means we need to start erasing after the last non-space character.
*/
std::string trim_space(std::string& str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_first_not_of(' ') + 1);
    return str;
}

/** createContact
 * .empty() : Check if a string (or other container like a vector) is empty
 * .eof() : Checks if an input stream has reached the end of a file or input
 * .clear() : Remove all the characters from the string, making the string empty
 */
bool    Contact::createContact(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNr;//need atoi?
    std::string secret;

    //firstname
    while (firstName.empty())
    {
        std::cout << "Please enter your first name: ";
        std::getline(std::cin, firstName);
        if (std::cin.eof()) return false;
    }
    //lastname
    while (lastName.empty())
    {
        std::cout << "Please enter your last name: ";
        std::getline(std::cin, lastName);
        if (std::cin.eof()) return false;
    }
    //nickname
    while (nickName.empty())
    {
        std::cout << "Please enter your nick name: ";
        std::getline(std::cin, nickName);
        if (std::cin.eof()) return false;
    }
    //phone nr
    while (phoneNr.empty())
    {
        std::cout << "Please enter your phone number: ";
        std::getline(std::cin, phoneNr);
        //check if is nbr
        if ( check_is_nbr(phoneNr) == false)
        {
            std::cout << "Enter valid phone number, plz?" << std::endl;
            phoneNr.clear();
            continue;
        }
        if (std::cin.eof()) return false;
    }
///should i add length limit??

    //secret
    while (secret.empty())
    {
        std::cout << "Tell me your darkest secret: ";
        std::getline(std::cin, secret);
        if (std::cin.eof()) return false;
    }
    setFirstname(trim_space(firstName));
    setLastname(trim_space(lastName));
    setNickname(trim_space(nickName));
    setPhoneNr(phoneNr);
    setSecret(trim_space(secret));
    std::cout << "✨ New Contact successfully added to phonebook! ✨" << std::endl;
    return true;
}

//OG
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