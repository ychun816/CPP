#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

//outcome:
//<bureaucrat> signed <form>
//<bureaucrat> couldn’t sign <form> because <reason>
void Bureaucrat::signForm(AForm& form) const
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

//ADDED
void Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldnt execute " << form.getName()
                  << " ,because " << e.what() << std::endl;
    }
}
