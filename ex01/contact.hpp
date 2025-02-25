#ifndef CONTACT_HPP
#define CONTACT_HPP

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
Contact::contact{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

// Function to take user input for contact details
Contact::void setContact(){

}

//to display the input stored in the variables
Contact::void displayContact() const{
    
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