#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>//For setw() func
#include <sstream> //For using std::stringstream

# define MAX_CONTACT 8 

class   Phonebook
{
    public:
        Phonebook(void);
        ~Phonebook(void);

    private:
        Contact	contacts[MAX_CONTACT];
        //contacts is an array of Contact objects.
        //contacts[i] accesses the i-th contact in the array.
        int current_count;
        int oldest_contact;

        //Shortens the string to fit within 10 characters
        std::string truncateName(const std::string& str) const;//const char* str in C

    public:
        void    addContact(const Contact& new_contact);
        void    searchContact(std::string input);
        void    displayAllContacts(void) const;
        void    displayCertainContact(int index) const;
};


#endif