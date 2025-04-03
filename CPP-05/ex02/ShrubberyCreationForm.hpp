#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <fstream> //for std::ofstream

//CONCRETE CLASS
//required grades: sign 145, exec 137
//Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
// take only one parameter in their constructor: the target of the form
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;//target of the form
    public:
        ShrubberyCreationForm();//default
        ShrubberyCreationForm(ShrubberyCreationForm& other);//copy
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);//assign
        ShrubberyCreationForm(std::string target);//init with target name
        ~ShrubberyCreationForm();//destructor

        //member funcs
        void execute(const Bureaucrat& executor) const;// override
        //without override -> If you accidentally misspell the function name or change its parameters, the compiler won't warn you that you're not actually overriding anything 
        //with override ->  for clarity&safety -> tells the compiler explicitly that this function is meant to override a function in the base class.
};



#endif 