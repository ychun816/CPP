#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// has no name, no grade, and no unique characteristic
class Intern
{
    public:
        ////constructor & destructor
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
    
        ////member funcs
        AForm& makeForm(std::string fromName, std::string target);

        ////NESTED CLASS (EXCEPTION)
        class WrongFormNameException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Error: Form name not found!";
                } 
        };
    
    private:
        //create forms funcs -> make in private&static
        static AForm* createShrubberyCreation(std::string& target){ return (new ShrubberyCreationForm(target)); };
        static AForm* createRobotomyRequest(std::string& target){ return (new RobotomyRequestForm(target)); };
        static AForm* createPresidentialForm(std::string& target){ return (new PresidentialPardonForm(target)); };
        
};

#endif 

/*NOTES
//pass-by-value (std::string target):
- Creates a new copy of the string in memory
- Modifications to target inside the function won't affect the original string
- Less efficient for large strings due to copying overhead
- Safer in terms of preventing unintended modifications

//pass-by-reference (std::string& target):
- Passes a reference to the original string (no copy is made)
- More efficient, especially for larger strings
- Can potentially modify the original string (though not in your case since you're not modifying it)
*/