#include "Form.hpp"
#include "Bureaucrat.hpp"

////NESTED CLASS
class GradeTooLowException : public std::exception
{
    public:
        const char *what() throw()
        {
            return "Form grade too low!";
        } 
};

class GradeTooHighException : public std::exception
{
    public:
        const char *what() throw()
        {
            return "Form grade too high!";
        } 
};

////CON&DE-STRUCTOR
Form::Form() : _name(NULL), _isSigned(false), _signGrade(0), _exeGrade(0)
{
    std:: cout << "--- Form default constructor called ---" << std::endl;
}

//Use Initialization List is better!
//-> const members must be initialized in the initialization list.
//-> _name(other._name), _signGrade(other._signGrade), and _exeGrade(other._exeGrade) ensure these values are set at construction.
Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) {}
// Form::Form(Form& other)
// {
//     _name = other._name;
//     _isSigned = other._isSigned;
//     _signGrade = other._signGrade;
//     _exeGrade = other._exeGrade;
//     std:: cout << "--- Form " << _name << "is copied ---" << std::endl;
// }

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // Can only modify non-const members
        this->_isSigned = other._isSigned;
        // Can't assign to _name, _signGrade, _exeGrade as they are const
    }
    std::cout << "--- Form " << _name << " is assigned ---" << std::endl;
    return (*this);
}
// Form& Form::operator=(const Form& other)
// {
//     if (this != &other)
//     {
//         this->_name = other._name;
//         this->_isSigned = other._isSigned;
//         this->_signGrade = other._signGrade;
//         this->_exeGrade = other._exeGrade;
//     }
//     std:: cout << "--- Form " << _name << "is assigned ---" << std::endl;
//     return (*this);
// }

Form::Form(std::string formName, int sGrade, int eGrade) :  _name(formName), _isSigned(false), _signGrade(sGrade), _exeGrade(eGrade)//init
{
    std:: cout << "--- (Constructor)Form " << _name << " is created ---" << std::endl;
}

Form::~Form()
{
    std:: cout << "--- (Destructor)Form " << _name << " is destroyed ---" << std::endl;
}

////MEMBER FUNCS
//getter
std::string Form::getName() const { return (_name); }
int Form::getSignGrade() const { return (_signGrade);}
int Form::getExeGrade() const { return (_exeGrade);}
bool Form::isSigned() const { return (_isSigned);}

//beSigned
//a bureacrat has a grade,
//a form has sign grade
//a bureaucrat needs to have higher grade, so can sign the form (or exe Form in ex02)
//if the grade is too low (>= 150), the bureaucrat wont sign the form
bool Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
    {
        throw GradeTooLowException();
        //return (false);
    }
    _isSigned = true;
    return (true);
}

////OPERATOR<< -> print result
//conclusion: From <form name> , required sign grade <> , required exe grade <> , 
std::ostream& operator<<(std::ostream& output, const Form& form)//const Form&? Form&?
{
    
    output << "Form: " << form.getName() 
            << " | Required sign grade: " << form.getSignGrade()
            << " | Required execute grade: " << form.getExeGrade() << std::endl
            << " || If signed: " << (form.isSigned() ? "NO" : "YES") << std::endl;
    return (output);
}