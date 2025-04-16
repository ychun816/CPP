#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
    private:
        std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        Bureaucrat(std::string _name, int grade);
        ~Bureaucrat();

        ////getter
        std::string getName() const;
        int getGrade() const;
        
        ////member funcs
        void signForm(AForm& form) const;
        void executeForm(AForm const& form) const;
};


#endif 