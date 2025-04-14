#ifndef BRUEAUCRAT_HPP
# define BRUEAUCRAT_HPP

// #include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

class Form;

//A constant name
//A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade
class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        Bureaucrat(std::string _name, int grade);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        
        //ex01 func
        //signForm() must call Form::beSigned() to attempt to sign the form
        void signForm(Form& form);

    private:
        std::string _name;
        int _grade;
};

#endif 