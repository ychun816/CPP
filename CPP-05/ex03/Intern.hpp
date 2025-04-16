#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

// has no name, no grade, and no unique characteristic
class Intern : public AForm
{
    public:
        ////constructor & destructor
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
    
        ////member funcs
        AForm& makeForm(std::string fromName, std::string target);

        ////exceptions
        class WrongFormNameException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Error: Form name not found!";
                } 
        };
        
};

#endif 