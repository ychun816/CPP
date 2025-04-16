#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <fstream>//for std::ofstream

//Derived Concrete class 
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();

        //member funcs to override
        void execute(const Bureaucrat& executor) const;
        AForm* createShrubberyCreation(std::string target);
};

#endif

/* SHRUBBERYCREATIONFORM RULES
- required grades: sign 145, exec 137
- Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it
- take only one parameter in their constructor: the target of the form
*/