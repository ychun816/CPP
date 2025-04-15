#include "Bureaucrat.hpp"
#include "AForm.hpp"

//con/de-structors
Bureaucrat::Bureaucrat() : _name(NULL), _grade(0)
{
    std:: cout << "--- Bureaucrat default constructor called ---" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
    _name = other._name;
    _grade = other._grade;
    std::cout << "--- Bureaucrat " << _name << " is copied ---" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    std::cout << "--- Bureaucrat " << _name << " is assigned ---" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string _name, int grade)
{
    this->_name = _name;
    this->_grade = grade;
    std:: cout << "--- Bureaucrat " << _name << " , grade [" << _grade << "] is created ---" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std:: cout << "--- Bureaucrat " << _name << " is destroyed ---" << std::endl;
}


////GETTER
std::string Bureaucrat::getName() const { return (_name);}
int Bureaucrat::getGrade() const { return (_grade);}


////MEMBER FUNCS
//sign form
void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this); 
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldnt sign, " << form.getName()
                  << " ,because " << e.what() << std::endl;
    }
}

//execute form
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
