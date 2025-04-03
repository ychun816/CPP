#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// #include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

class AForm;

//A constant name
//A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade
class Bureaucrat
{
    public:
        Bureaucrat();//default
        Bureaucrat(Bureaucrat& other);//copy
        Bureaucrat& operator=(Bureaucrat& other);//assign
        Bureaucrat(std::string _name, int grade);//init with name and grade
        ~Bureaucrat();//destructor

        std::string getName() const;
        int getGrade() const;
        
        //ex01 func
        void signForm(AForm& form) const;

        //ADDED
        void executeForm(AForm const& form) const;
        //If successful, print something like:<bureaucrat> executed <form>
        //If not, print an explicit error message

    private:
        std::string _name;
        int _grade;
};

// std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif 