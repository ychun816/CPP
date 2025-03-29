#include "Contact.hpp"

Contact::Contact(void){}
Contact::~Contact(void){}

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
 * @note std::string& str: the parameter str is passed by reference (&)
 * @note [function] str.erase(start_position, length);
 * Find the first character in a string that is NOT part of a given set of characters
 * @note str.erase(str.find_first_not_of(' ') + 1);
 * Returns the index of the last non-space character.
 * +1: We add 1 because we want to remove the space after the last non-space character, which means we need to start erasing after the last non-space character.
 * @note std::string::npos 
 * -> is a constant representing the largest possible value for size_t.
 * -> indicate that a search for a substring failed (i.e., the substring was not found).
 */
std::string trim_space(std::string& str)
{
    size_t end;

    str.erase(0, str.find_first_not_of(' '));
    end = str.find_last_not_of(' ');
    if (end != std::string::npos)
        str.erase(end + 1);
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
    std::string phoneNr;
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
        if ( check_is_nbr(phoneNr) == false)//check if is nbr
        {
            std::cout << "Enter valid phone number, plz?" << std::endl;
            phoneNr.clear();
            continue;
        }
        if (std::cin.eof()) return false;
    }

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
    std::cout << std::endl;
    std::cout << "✨ New Contact successfully added to phonebook! ✨" << std::endl;
    // Contact::displayContact();
    return true;
}

/** display contact */
 void Contact::displayContact(void) const
 {
    std::cout << "First Name: " << getFirstname() << std::endl;
    std::cout << "Last Name: " << getLastname() << std::endl;
    std::cout << "Nick Name: " << getNickname() << std::endl;
    std::cout << "Phone Number: " << getPhoneNr() << std::endl;
    std::cout << "Darkest Secret: " << getSecret() << std::endl;
 }