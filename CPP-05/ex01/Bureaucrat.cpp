#include "Bureaucrat.hpp"
#include "Form.hpp"

///nested classes
//custom exception classes
//Both classes inherit from std::exception and override the what() function to return custom error messages.
//: public std::exception → This makes it a subclass of std::exception, allowing it to be used in try-catch blocks.
//what() const throw() → Overrides std::exception::what() to return "Grade is too high!"
//note!! throw() must come after the function parameters, not before the return type
// class Bureaucrat::GradeTooHighException : public std::exception
// {
//     public:
//         const char* what() const throw()
//         {
//             return ("Grade is too high!");
//         }
// };

// class Bureaucrat::GradeTooLowException : public std::exception
// {
//     public:
//         const char* what() const throw()
//         {
//             return ("Grade is too low!");
//         }
// };

//con/de-structors
Bureaucrat::Bureaucrat() : _name(NULL), _grade(0)//default
{
    std:: cout << "--- Bureaucrat default constructor called ---" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)//copy
{
    _name = other._name;
    _grade = other._grade;
    std::cout << "--- Bureaucrat " << _name << " is copied ---" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)//assign
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    std::cout << "--- Bureaucrat " << _name << " is assigned ---" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string _name, int grade)//init with name and grade
{
    this->_name = _name;
    this->_grade = grade;
    std:: cout << "--- Bureaucrat " << _name << " , grade [" << _grade << "] is created ---" << std::endl;
}

Bureaucrat::~Bureaucrat()//destructor
{
    std:: cout << "--- Bureaucrat " << _name << " is destroyed ---" << std::endl;
    // std:: cout << "--- Bureaucrat default destructor called ---" << std::endl;
}


//getter
std::string Bureaucrat::getName() const { return (_name);}
int Bureaucrat::getGrade() const { return (_grade);}

//member funcs
// grade 1 is the highest ; 150 the lowest
// incrementing a grade 3 should result in a grade 2 for the bureaucrat.
// void Bureaucrat::incrementGrade()
// {
//     if (_grade <= 1)
//         throw Bureaucrat::GradeTooHighException();
//     _grade--;
// }

// void Bureaucrat::decrementGrade()
// {
//     if (_grade >= 150)
//         throw Bureaucrat::GradeTooLowException();
//     _grade++;
// }

//sign form
//Uses try-catch to handle form signing errors.
//@note *this Refers to the Current Object
//Inside a member function of the Bureaucrat class, this is a pointer to the calling object.
//*this dereferences the pointer, giving the actual object.
//Since beSigned() expects a const Bureaucrat&, we can pass *this directly.

//outcome:
//<bureaucrat> signed <form>
//<bureaucrat> couldn’t sign <form> because <reason>
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);//beSigned() Takes a Bureaucrat Object -> *this refers to the current object: 
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldnt sign, " << form.getName()
                  << " ,because " << e.what() << std::endl;
    }
}

/*
//operator<<
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
    // <name>, bureaucrat grade <grade>
    output << bureaucrat.getName() << ", bureaucrat grade [ " << bureaucrat.getGrade() << " ] " << std::endl;
    return (output);  
}
*/