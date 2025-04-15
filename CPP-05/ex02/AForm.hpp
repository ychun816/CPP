#ifndef AForm_HPP
# define AForm_HPP

// #include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; //Forward declaration (fixes circular dependency)

//ABSTRACT CLASS
//the base class Form must be an abstract class
//Make It an Abstract Class!! -> derived class must implement the pure virtual function
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _exeGrade;

    public:
        ////construct/destruct
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        AForm(std::string formName, int sGrade, int eGrade);
        virtual~AForm();

        ////getter
        std::string getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned() const;

        ////member funcs
        //check if signed
        bool beSigned(const Bureaucrat& bureaucrat);
        
        ////nested class
        //AForm::GradeTooHighException and AForm::GradeTooLowException
        class GradeTooLowException{};
        class GradeTooHighException{};
        class FormNotSignedException{};
        
        virtual void execute(Bureaucrat const & executor) const = 0;//pure virtual
};

////NESTED CLASS
class GradeTooLowException : public std::exception
{
    public:
        const char *what() const throw()
        {
            return "Form grade too low!";
        } 
};

class GradeTooHighException : public std::exception
{
    public:
        const char *what() const throw()
        {
            return "Form grade too high!";
        } 
};

//added exception class
class FormNotSignedException : public std::exception
{
    public:
        const char *what() const throw()
        {
            return "Form is not signed!";
        }
};


std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif
