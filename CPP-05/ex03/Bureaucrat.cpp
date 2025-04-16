#include "Bureaucrat.hpp"
#include "AForm.hpp"

//// constructor & destructor 
Bureaucrat::Bureaucrat() : _name("DEFAULT"), _grade(0)
{
    std:: cout << "--- Bureaucrat default constructor called ---" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    // _name = other._name;
    // _grade = other._grade;
    std::cout << "--- Bureaucrat " << _name << " Copy Constructor calld ---" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
        if (this->_grade < 1)
            throw AForm::GradeTooHighException();
        if (this->_grade > 150)
            throw AForm::GradeTooLowException();
    }
    std::cout << "--- Bureaucrat " << _name << " Assign Operator called ---" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw AForm::GradeTooHighException();
    if (this->_grade > 150)
        throw AForm::GradeTooLowException();
    // this->_name = _name;
    // this->_grade = grade;
    std:: cout << "--- Bureaucrat " << _name << " ; grade [" << _grade << "] | Assignment Constructor called ---" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std:: cout << "--- Bureaucrat " << _name << " Destructor called ---" << std::endl;
}

//getter
std::string Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

////member funcs
//sign form
//Uses try-catch to handle form signing errors.
//@note *this Refers to the Current Object
//Inside a member function of the Bureaucrat class, this is a pointer to the calling object.
//*this dereferences the pointer, giving the actual object.
//Since beSigned() expects a const Bureaucrat&, we can pass *this directly

//outcome:
//<bureaucrat> signed <form>
//<bureaucrat> couldn’t sign <form> because <reason>
void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign [ " << form.getName()
                  << " ], because: " << e.what() << std::endl;
    }
}
