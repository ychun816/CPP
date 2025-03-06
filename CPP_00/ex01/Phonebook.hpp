#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

# define MAX_CONTACT 8

class   Phonebook
{
    public:
    Phonebook(void);
    ~Phonebook(void);

    void    addContact(const Contact& new_contact); 
    void    displayAllContacts(void) const;
    void    displayContact(int index) const;

    private:
    // Contact	contacts[8];
    int current_count;
    int oldest_contact;

    std::string truncate(const std::string& str) const;//const char* str in C
}


#endif