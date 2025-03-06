#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>  // For std::cout, std::cin
#include <string>    // For std::string, std::string::npos

//The underscore (_) prefix is a common convention in C++ 
//to indicate that these variables are private and should only be accessed through the class's public getter and setter methods.
class Contact
{
    public:
        Contact();  // Constructor
        ~Contact(); //deconstructor

    //set value 
    void    setFirstname(std::string str);
    void    setLastname(std::string str);
    void    setNickname(std::string str);
    void    setPhoneNr(std::string str);
    void    setSecret(std::string str);

    //get value -- getter method
    std::string getFirstname(void) const { return _firstName; }
    std::string getLastname(void) const { return _lastName; }
    std::string getNickname(void) const { return _nickName; }
    std::string getPhoneNr(void) const { return _phoneNr; }
    std::string getSecret(void) const { return _secret; }

    bool createContact(void);
    void displayContact(void) const;
    std::string searchContact(std::string input);

    //private attributes to store contact details
    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNr;
    std::string _secret;
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