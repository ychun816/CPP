#ifndef BRUEAUCRAT_HPP
# define BRUEAUCRAT_HPP

#include <iostream>
#include <string>

//A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade
class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        Bureaucrat(std::string _name, int grade);
        ~Bureaucrat();

        ////getter 
        std::string getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();
        
        //nested classes //custom exception classes
        class GradeTooLowException;
        class GradeTooHighException;
    
    private:
        std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return ("Grade is too high!");
        }
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return ("Grade is too low!");
        }
};


#endif 

/* NOTES
////nested classes
- custom exception classes
- Both classes inherit from std::exception and override the what() function to return custom error messages.
- public std::exception → This makes it a subclass of std::exception, allowing it to be used in try-catch blocks.
- what() const throw() → Overrides std::exception::what() to return "Grade is too high!"
- note!! throw() must come after the function parameters, not before the return type

*/
