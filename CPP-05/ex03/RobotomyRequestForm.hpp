#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib> // for rand()

//Derived Concrete class 
class RobotomyRequestForm : public AForm
{
    private:
            std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(RobotomyRequestForm& other);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();

        //memeber func to override
        void execute(Bureaucrat const& executor) const;
};

#endif

/* ROBOTOMYREQUESTFORM RULES
- required grades: sign 72, exec 45
- Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time
- Otherwise, it informs that the robotomy failed
- take only one parameter in their constructor: the target of the form
*/