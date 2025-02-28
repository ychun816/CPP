#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>  // For std::cout, std::cin
#include <string>    // For std::string
// #include <iomanip>   // For formatted table output


//The underscore (_) prefix is a common convention in C++ 
//to indicate that these variables are private and should only be accessed through the class's public getter and setter methods.
class Contact
{
    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNr;
    std::string _secret;

    public:
    Contact();  // Constructor
    void setContact();
    void displayContact() const;// CANNOT modify any member variables
};

#endif

/*
Understanding private: and public:

These are access specifiers in C++ that control who can access the members (variables & functions) of a class.

private: (Only accessible inside the class)
- Members (variables/functions) under private: cannot be accessed from outside the class.
- Only the class's own functions (methods) can access them.
- This is useful for encapsulation—it hides details from outside interference.

public: (Accessible from outside the class)
- Members under public: can be accessed from anywhere.
- Typically used for functions that let users interact with private data.
*/