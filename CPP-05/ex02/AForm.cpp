#include "AForm.hpp"
#include "Bureaucrat.hpp"

////CONSTRUCTOR & DESTRUCTOR
AForm::AForm() : _name("DEFAULT"), _isSigned(false), _signGrade(0), _exeGrade(0)
{
    std:: cout << "--- AForm Default Constructor called ---" << std::endl;
}

//Use Initialization List is better!
//-> const members must be initialized in the initialization list!!
AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) 
{
    std::cout << "--- AForm " << _name << " Copy Constructor called ---" << std::endl;
}

// Can only modify non-const members
// Can't assign to _name, _signGrade, _exeGrade as they are const
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    std::cout << "--- AForm " << _name << " Assign Operator called ---" << std::endl;
    return (*this);
}

AForm::AForm(std::string formName, int sGrade, int eGrade) :  _name(formName), _isSigned(false), _signGrade(sGrade), _exeGrade(eGrade)
{
    std:: cout << "--- AForm " << _name << " Constructor called ---" << std::endl;
}

AForm::~AForm()
{
    std:: cout << "--- AForm " << _name << " Destructor called ---" << std::endl;
}


////GETTER
std::string AForm::getName() const { return (_name); }
int AForm::getSignGrade() const { return (_signGrade);}
int AForm::getExeGrade() const { return (_exeGrade);}
bool AForm::isSigned() const { return (_isSigned);}

////MEMBER FUNCS
//beSigned
//a bureaucrat needs to have higher grade(=lower in nb), so can sign the AForm / exe AForm
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

//execute
//Only need to take care of the non-exe cases -> cannot exe cases : (1) not signed / (2) executor's grade too low
//no need or exe actions! -> in concretee classes will override the pure virtual func
//should call executeAction()
void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > _exeGrade)
        throw GradeTooLowException();
}

////OPERATOR<<
std::ostream& operator<<(std::ostream& output, const AForm& form)
{
    
    output << "AForm: " << form.getName() 
            << " | Required sign grade: " << form.getSignGrade()
            << " | Required execute grade: " << form.getExeGrade() << std::endl
            << " || If signed: " << (form.isSigned() ? "NO" : "YES") << std::endl;
    return (output);
}
