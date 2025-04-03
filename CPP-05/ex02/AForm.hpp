#ifndef AForm_HPP
# define AForm_HPP

// #include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;  // ✅ Forward declaration (fixes circular dependency)

//ABSTRACT CLASS
//the base class Form must be an abstract class
//Make It an Abstract Class!! -> derived class must implement the pure virtual function
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;//The minimum grade required to sign the AForm.
        const int _exeGrade;//The minimum grade required to execute the AForm. -> for ex02

    public:
        ////construct/destruct
        AForm();
        AForm(const AForm& other);//copy
        AForm& operator=(const AForm& other);//assign
        AForm(std::string formName, int sGrade, int eGrade);//init
        virtual~AForm();

        //member function to the AForm that takes a Bureaucrat as a parameter.
        //It changes the AForm’s status to signed if the bureaucrat’s grade is high enough (greater than or equal to the required one)
        bool beSigned(const Bureaucrat& bureaucrat);
        
        ////member funcs
        //getter
        std::string getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned() const;
                
        ////nested class
        //AForm::GradeTooHighException and AForm::GradeTooLowException
        class GradeTooLowException{};
        class GradeTooHighException{};
        //added
        class FormNotSignedException{};
        
        //ADDED
        virtual void execute(Bureaucrat const & executor) const = 0; //Make execute() pure virtual
        //implement a func to execute the AForm’s action in the concrete classes
};

std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif
