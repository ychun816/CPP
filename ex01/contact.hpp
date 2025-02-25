#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>  // For std::cout, std::cin
#include <string>    // For std::string
#include <iomanip>   // For formatted table output


class Contact {

    private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    public:
    contact();  // Constructor
    void setContact();
    void displayContact() const;// CANNOT modify any member variables
};

//contact struct varaible to hold the user inputs
Contact::contact {
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
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
    std::getline(std::cin, phoneNumber);//number can also use this?
    while (phoneNumber.empty())
    {
        std::cout << "Field cannot be empty!! Enter Phone Number AGAIN: ";
        std::getline(std::cin, phoneNumber);
    }
    //dark secret
    std::cout << "You Darket Secret?: "
    std::getline(std::cin, darkestSecret);
    while (darkestSecret.empty())
    {
        std::cout << "Field cannot be empty!! Enter AGAIN: ";
        std::getline(std::cin, darkestSecret);
    }
    std::cout << "✅ CONTACT INFO SAVED!\n";
}

//to display the input stored in the variables
Contact::void displayContact() const{
    std::cout << "📞 Contact Info:\n";
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lasttName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

#endif

/*
Understanding private: and public:

These are access specifiers in C++ that control who can access the members (variables & functions) of a class.

📌 private: (Only accessible inside the class)
- Members (variables/functions) under private: cannot be accessed from outside the class.
- Only the class's own functions (methods) can access them.
- This is useful for encapsulation—it hides details from outside interference.

📌 public: (Accessible from outside the class)
- Members under public: can be accessed from anywhere.
- Typically used for functions that let users interact with private data.


*/