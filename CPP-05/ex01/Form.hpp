#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

// class Bureaucrat;  // ✅ Forward declaration (fixes circular dependency)

//private attributes:
// • A constant name.
// • A boolean indicating whether it is signed (at construction, it is not). 
// • A constant grade required to sign it.
// • A constant grade required to execute it.

// will be thrown if a form’s grade is out of bounds: Form::GradeTooHighException and Form::GradeTooLowException.
class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;//The minimum grade required to sign the form.
        const int _exeGrade;//The minimum grade required to execute the form. -> for ex02

    public:
        ////construct/destruct
        Form();
        Form(const Form& other);//copy
        Form& operator=(const Form& other);//assign
        Form(std::string formName, int sGrade, int eGrade);//init
        ~Form();

        //member function to the Form that takes a Bureaucrat as a parameter.
        //It changes the form’s status to signed if the bureaucrat’s grade is high enough (greater than or equal to the required one)
        //grade 1 is higher than grade 2
        bool beSigned(const Bureaucrat& bureaucrat);
        
        ////member funcs
        //getter
        std::string getName();
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned();

        ////nested class
        //Form::GradeTooHighException and Form::GradeTooLowException
        class GradeTooLowException;
        class GradeTooHighException;

};

std::ostream& operator<<(std::ostream& output, const Form& form);


#endif

/*
If you're only using the Bureaucrat class as a reference or pointer in the Form class (i.e., you don't need to access its members), forward declaring is typically sufficient and can reduce unnecessary dependencies.
If you need the complete definition of Bureaucrat for things like member function calls, or if you plan to use it in other parts of the Form class, then including Bureaucrat.hpp directly would be the better choice.

*/