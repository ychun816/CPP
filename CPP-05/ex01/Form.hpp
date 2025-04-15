#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>


//private attributes:
// • A constant name
// • A boolean indicating whether it is signed (at construction, it is not) 
// • A constant grade required to sign it
// • A constant grade required to execute it

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _exeGrade;

    public:
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        Form(std::string formName, int sGrade, int eGrade);
        ~Form();

        ////getter
        std::string getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned() const;

        ////member funcs
        bool beSigned(const Bureaucrat& bureaucrat);
    
        ////nested class
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form grade too low!";
                } 
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form grade too high!";
                } 
        };

};

std::ostream& operator<<(std::ostream& output, const Form& form);


#endif
