#include "PresidentialPardonForm.hpp"

////CONSTRUCTOR & DESTRUCTOR
PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("DEFAULT")
{
    std:: cout << "--- PresidentialPardonForm default constructor called ---" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
    // _target = other._target;
    std::cout << "--- PresidentialPardonForm Copy Constructor called ---" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout << "--- PresidentialPardonForm " << _target << " is assigned ---" << std::endl;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    // this->_target = target;
    std:: cout << "--- PresidentialPardonForm with target [" << _target << "] Assign Constructor called ---" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std:: cout << "--- PresidentialPardonForm Destructor called ---" << std::endl;
}

////member funcs
//execute
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    //if cannot signed&execute cases frm AForm
    (void)executor;//put void?
    std::cout << "🔏 PresidentialPardonForm " << _target << " has been pardoned by Zaphod Beeblebrox 🔏" << std::endl;
}
