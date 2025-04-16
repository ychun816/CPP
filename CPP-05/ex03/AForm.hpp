#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

//Base Abstract Class
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
        virtual ~AForm();

        ////getter
        std::string getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned() const;

        ////member funcs
        bool beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;//pure virtual
        
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

        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Form is not signed!";
                }
        };
};

std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif
