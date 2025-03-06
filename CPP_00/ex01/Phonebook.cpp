#include "Phonebook.hpp"

//constructor
Phonebook::Phonebook(void)
{
    current_count = 0;//need init?
    oldest_contact = 0;//need init?
}

//decontructor
Phonebook::~Phonebook(void)
{
}

/** Add Contact
//If still space(less than 8) -> Add the contact && increment current_count
//If no space, phonebook full -> Overwrite the oldest contact
*/
void    Phonebook::addContact(const Contact& new_contact)
{
    if (current_count < MAX_CONTACT)
        contacts[current_count++] = new_contact;
    else
    {
        contacts[oldest_contact] = new_contact;
        //+1 moves oldest_contact to the next index
        //% 8 loops it back to 0 when it reaches 8
        oldest_contact = (oldest_contact + 1) % 8;
    }
}

/** display all contacts
std::setw(10): Set column width with 10 characters

*/
void    Phonebook::displayAllContacts(void) const
{
    std::cout << std::setw(10) << "Index" << " | "
        << std::setw(10) << "First Name" << " | "
        << std::setw(10) << "Last Name" << " | "  << std::endl;
    for (int i = 0; i < current_count; i++)
    {
        std::cout << std::setw(10) << (i + 1) << " | " //Display index starting from 1
            << std::setw(10) << truncateName(contacts[i].getFirstname()) << " | "
            << std::setw(10) << truncateName(contacts[i].getLastname()) << " | " << std::endl;
            // << std::setw(10) << truncateName(contacts[i].getNickname()) << " | " << std::endl;
    }

}

/** search contact 
@note
//std::stringstream [object- "extract"]  -> extract numbers
//>> (Extraction Operator)
//extract >> number : the variable number stores the value/data extracted frm extract (by std::stringstream)
*/
void    Phonebook::searchContact(std::string input)
{
    int index;

    // std::getline(std::cin, input);
    std::stringstream extract_nb(input);
    if (extract_nb >> index && extract_nb.eof())
        Phonebook::displayCertainContact(index);
    else
        std::cout << "Invalid input/index. Plz type a number." << std::endl;
}

/** display certain contact  */
void    Phonebook::displayCertainContact(int index) const
{
    if (index < 1 || index > 8)
        std::cout << "Invalid index! Try another plz." << std::endl;
    else
        contacts[index - 1].displayContact();
}

/** truncate 
//.substr() : 
*/
std::string Phonebook::truncateName(const std::string& str) const//const char* str in C
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}