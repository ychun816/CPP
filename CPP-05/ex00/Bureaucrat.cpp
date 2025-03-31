#include "Bureaucrat.hpp"

//con/de-structors
Bureaucrat::Bureaucrat() : _name(NULL), _grade(0)//default
{
    std:: cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)//copy
{
    _name = other._name;
    _grade = other._grade;
    std::cout << "Bureaucrat " << _name << " is copied" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)//assign
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    std::cout << "Bureaucrat " << _name << " is assigned" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string _name, int grade)//init with name and grade
{
    this->_name = _name;
    this->_grade = grade;
    std:: cout << "Bureaucrat " << _name << " with grade [" << _grade << "] is created" << std::endl;
}

Bureaucrat::~Bureaucrat()//destructor
{
    std:: cout << "Bureaucrat default destructor called" << std::endl;
}


//getter
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}



//operator<<
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);
{
    // <name>, bureaucrat grade <grade>
    output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (output);
}

/*
The thrown exceptions must be catchable using try and catch blocks:abs

try
{
    //do some stuff with bureaucrats
}
catch (std::exception & e)
{
    //handle exception
}

*/