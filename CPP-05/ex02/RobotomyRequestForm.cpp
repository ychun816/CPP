#include "RobotomyRequestForm.hpp"

////CONSTRUCTOR & DESTRUCTOR
RobotomyRequestForm::RobotomyRequestForm() :  AForm(), _target("DEFAULT")
{
    std:: cout << "--- RobotomyRequestForm default Constructor called ---" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
    // _target = other._target;
    std::cout << "--- RobotomyRequestForm Copy Constructor called ---" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout << "--- RobotomyRequestForm Assign Operator called ---" << std::endl;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    // this->_target = target;
    std:: cout << "--- RobotomyRequestForm with target [ " << _target << " ] Assign Constructor called ---" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std:: cout << "--- RobotomyRequestForm Destructor called ---" << std::endl;
}

////MEMBER FUNCS
/** execute
 * @note rand() % 2
 * rand() generates a random number
 * if (rand() % 2) => 50% chance the condition will be true (1) or false (0)
 */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    (void)executor;//put void?

    rand() % 2 ? \
    std::cout << "🔩🔩🔩 RobotomyRequestForm " << _target << " has been robotomized successfully 🔩🔩🔩" << std::endl : \
    std::cout << "❌ RobotomyRequestForm " << _target << " robotomy failed ❌" << std::endl;
}
