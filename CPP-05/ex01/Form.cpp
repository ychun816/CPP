#include "Form.hpp"
#include "Bureaucrat.hpp"

////CONSTRUCTOR & DESTRUCTOR
Form::Form() : _name("DEFAULT"), _isSigned(false), _signGrade(0), _exeGrade(0)
{
    std:: cout << "--- Form Default Constructor called ---" << std::endl;
}

//Use Initialization List is better!
Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) 
{
    std::cout << "--- Form " << _name << " Copy Constructor called ---" << std::endl;
}

//operator
// Can't assign to _name, _signGrade, _exeGrade as they are const
Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    std::cout << "--- Form " << _name << " Assign Operator called ---" << std::endl;
    return (*this);
}

//set buffer for lowest & highest grades
Form::Form(std::string formName, int sGrade, int eGrade) : _name(formName), _isSigned(false), _signGrade(sGrade), _exeGrade(eGrade)
{
    if (sGrade < 1 || eGrade < 1)
        throw Form::GradeTooHighException();
    if (sGrade > 150 || eGrade > 150)
        throw Form::GradeTooLowException();
    std:: cout << "--- Form " << _name << " Constructor called ---" << std::endl;
}

Form::~Form()
{
    std:: cout << "--- Form " << _name << " Destructor called ---" << std::endl;
}

////getter
std::string Form::getName() const { return (_name); }
int Form::getSignGrade() const { return (_signGrade);}
int Form::getExeGrade() const { return (_exeGrade);}
bool Form::isSigned() const { return (_isSigned);}


////MEMBER FUNCS
//beSigned
//a bureacrat has a grade, a form has sign grade
//a bureaucrat needs to have higher grade, so can sign the form (or exe Form in ex02)
//if the grade is too low (>= 150), the bureaucrat wont sign the form
bool Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)// || bureaucrat.getGrade() > 150
    {
        throw GradeTooLowException();
        // _isSigned = false;
        // return (false);
    }
    if (bureaucrat.getGrade() < 1)
    {
        throw GradeTooHighException();
        // _isSigned = false;
        // return (false);
    }
    this->_isSigned = true;
    return (true);
}

////OPERATOR<<
//From <form name> , required sign grade <> , required exe grade <> , 
std::ostream& operator<<(std::ostream& output, const Form& form)//const Form&? Form&?
{
    output << "Form: " << form.getName() 
            << " | Required sign grade: " << form.getSignGrade()
            << " | Required execute grade: " << form.getExeGrade() << std::endl
            << " || If signed: " << (form.isSigned() ? "YES" : "NO") << std::endl;//true : false(1 : 0)
    return (output);
}