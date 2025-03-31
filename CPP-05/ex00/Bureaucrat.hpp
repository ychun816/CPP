#ifndef BRUEAUCRAT_HPP
# define BRUEAUCRAT_HPP

#include <iostream>
#include <string>

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
        
        void incrementGrade();
        void decrementGrade();
        
        //nested classes
        //custom exception classes
        class GradeTooLowException;
        class GradeTooHighException;
    
    private:
        std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif 


