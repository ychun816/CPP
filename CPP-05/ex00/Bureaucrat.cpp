#include "Bureaucrat.hpp"

////constructors & destructor
Bureaucrat::Bureaucrat() : _name("DEFAULT"), _grade(0)
{
    std:: cout << "--- Bureaucrat default constructor called ---" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
    _name = other._name;
    _grade = other._grade;
    std::cout << "--- Bureaucrat " << _name << " Copy Constructor calld ---" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    std::cout << "--- Bureaucrat " << _name << " Assign Operator called ---" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    // this->_name = _name;
    // this->_grade = grade;
    std:: cout << "--- Bureaucrat " << _name << " ; grade [" << _grade << "] | Assignment Constructor called ---" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std:: cout << "--- Bureaucrat " << _name << " Destructor called ---" << std::endl;
}


////getter
std::string Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }


////member funcs
// grade 1 is the highest ; 150 the lowest
// incrementing a grade 3 should result in a grade 2 for the bureaucrat

// if it's already at 1, decreasing it would make it 0 or below, which is invalid!!
// Check before decrement!!!
void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

// if it's already at 150, increasing it would make it 151 or above, which is invalid!!
void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

//operator<<
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
    output << bureaucrat.getName() << ", bureaucrat grade [ " << bureaucrat.getGrade() << " ] " << std::endl;
    return (output);
}
