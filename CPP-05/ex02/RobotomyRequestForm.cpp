#include "RobotomyRequestForm.hpp"

//construc & deconstruc
RobotomyRequestForm::RobotomyRequestForm() : _target(NULL)//default
{
    std:: cout << "--- RobotomyRequestForm default constructor called ---" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)//copy
{
    _target = other._target;
    std::cout << "--- RobotomyRequestForm " << _target << " is copied ---" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)//assign
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout << "--- RobotomyRequestForm " << _target << " is assigned ---" << std::endl;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)//init with name and grade
{
    this->_target = target;
    std:: cout << "--- RobotomyRequestForm with target [" << _target << "] is created ---" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()//destructor
{
    // std:: cout << "--- RobotomyRequestForm default destructor called ---" << std::endl;
    std:: cout << "--- RobotomyRequestForm " << _target << " is destroyed ---" << std::endl;
}

//execute
/**
 *  * @note rand() % 2
 * rand() generates a random number.
 * % 2 takes the remainder when dividing by 2, so the result is either 0 or 1
 * if (rand() % 2) => 50% chance the condition will be true (1) or false (0).
 */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    //if cannot signed&execute cases frm AForm
    rand() % 2 ? \
    std::cout << "🔩🔩🔩 RobotomyRequestForm " << _target << " has been robotomized successfully 🔩🔩🔩" << std::endl : \
    std::cout << "❌ RobotomyRequestForm " << _target << " robotomy failed ❌" << std::endl;
}
