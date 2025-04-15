#include "AForm.hpp"
#include "Bureaucrat.hpp"


////CON&DE-STRUCTOR
AForm::AForm() : _name(NULL), _isSigned(false), _signGrade(0), _exeGrade(0)
{
    std:: cout << "--- Form default constructor called ---" << std::endl;
}

//Use Initialization List is better!
//-> const members must be initialized in the initialization list.
//-> _name(other._name), _signGrade(other._signGrade), and _exeGrade(other._exeGrade) ensure these values are set at construction.
AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // Can only modify non-const members
        this->_isSigned = other._isSigned;
        // Can't assign to _name, _signGrade, _exeGrade as they are const
    }
    std::cout << "--- AForm " << _name << " is assigned ---" << std::endl;
    return (*this);
}

AForm::AForm(std::string formName, int sGrade, int eGrade) :  _name(formName), _isSigned(false), _signGrade(sGrade), _exeGrade(eGrade)//init
{
    std:: cout << "--- (Constructor)AForm " << _name << " is created ---" << std::endl;
}

AForm::~AForm()
{
    std:: cout << "--- (Destructor)AForm " << _name << " is destroyed ---" << std::endl;
}

////MEMBER FUNCS
//getter
std::string AForm::getName() const { return (_name); }
int AForm::getSignGrade() const { return (_signGrade);}
int AForm::getExeGrade() const { return (_exeGrade);}
bool AForm::isSigned() const { return (_isSigned);}

//beSigned
//a bureacrat has a grade,
//a AForm has sign grade
//a bureaucrat needs to have higher grade, so can sign the AForm (or exe AForm in ex02)
//if the grade is too low (>= 150), the bureaucrat wont sign the AForm
bool AForm::beSigned(const Bureaucrat& bureaucrat)
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
//conclusion: From <AForm name> , required sign grade <> , required exe grade <> , 
std::ostream& operator<<(std::ostream& output, const AForm& form)//const AForm&? AForm&?
{
    
    output << "AForm: " << form.getName() 
            << " | Required sign grade: " << form.getSignGrade()
            << " | Required execute grade: " << form.getExeGrade() << std::endl
            << " || If signed: " << (form.isSigned() ? "NO" : "YES") << std::endl;
    return (output);
}

//ADDED
//execute() should call executeAction()
//a pure virtual function that each subclass overrides
//@note only need to take care of the non-exe cases
//@note no need or exe actions, cuz in concretee classes will be valid execute funcs
void AForm::execute(Bureaucrat const & executor) const
{
    //cannot exe cases : 1 not signed / 2 executor's grade too low
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > _exeGrade)
        throw GradeTooLowException();
}
