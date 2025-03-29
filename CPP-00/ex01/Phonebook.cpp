#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    current_count = 0;
    oldest_contact = 0;
}

Phonebook::~Phonebook(void){}

/** Add Contact
 * - If still space(less than 8) -> Add the contact && increment current_count
 * - If no space, phonebook full -> Overwrite the oldest contact
 * @note
 * +1 moves oldest_contact to the next index
 * % 8 loops it back to 0 when it reaches 8
*/
void    Phonebook::addContact(const Contact& new_contact)
{
    if (current_count < MAX_CONTACT)
        contacts[current_count++] = new_contact;
    else
    {
        contacts[oldest_contact] = new_contact;

        oldest_contact = (oldest_contact + 1) % 8;
    }
}

/** display all contacts
 * @note std::setw(10)
 * Set column width with 10 characters
 * @note
 * Display index starting from 1
*/
void    Phonebook::displayAllContacts(void) const
{
    std::cout << std::setw(10) << "Index" << " | "
        << std::setw(10) << "First Name" << " | "
        << std::setw(10) << "Last Name" << " | " 
        << std::setw(10) << "Nick Name" << " | "  
        << std::endl;
    for (int i = 0; i < current_count; i++)
    {
        std::cout << std::setw(10) << (i + 1) << " | "
            << std::setw(10) << truncateName(contacts[i].getFirstname()) << " | "
            << std::setw(10) << truncateName(contacts[i].getLastname()) << " | " 
            << std::setw(10) << truncateName(contacts[i].getNickname()) << " | " << std::endl;
    }
}

/** search contact 
 * @note std::stringstream [object- "extract"]
 * -> extract numbers
 * @note >> (Extraction Operator)
 * @note extract >> number
 * -> The variable number stores the value/data extracted frm extract (by std::stringstream)
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
 * @note .substr() 
 * to truncate the string to 10 characters 
*/
std::string Phonebook::truncateName(const std::string& str) const
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}