#include "PresidentialPardonForm.hpp"


//construc & deconstruc
PresidentialPardonForm::PresidentialPardonForm() : _target(NULL)//default
{
    std:: cout << "--- PresidentialPardonForm default constructor called ---" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)//copy
{
    _target = other._target;
    std::cout << "--- PresidentialPardonForm " << _target << " is copied ---" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)//assign
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout << "--- PresidentialPardonForm " << _target << " is assigned ---" << std::endl;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)//init with name and grade
{
    this->_target = target;
    std:: cout << "--- PresidentialPardonForm with target [" << _target << "] is created ---" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()//destructor
{
    // std:: cout << "--- PresidentialPardonForm default destructor called ---" << std::endl;
    std:: cout << "--- PresidentialPardonForm " << _target << " is destroyed ---" << std::endl;
}

//mem func
//exe
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    //if cannot signed&execute cases frm AForm
    std::cout << "🔏 PresidentialPardonForm " << _target << " has been pardoned by Zaphod Beeblebrox 🔏" << std::endl;
}
