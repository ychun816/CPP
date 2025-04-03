#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>  // Required for rand()

//required grades: sign 72, exec 45
//Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time
//Otherwise, it informs that the robotomy failed
// take only one parameter in their constructor: the target of the form
class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();//default
        RobotomyRequestForm(RobotomyRequestForm& other);//copy
        RobotomyRequestForm& operator=(RobotomyRequestForm& other);//assign
        RobotomyRequestForm(std::string target);//init with name and grade
        ~RobotomyRequestForm();//destructor

        //memeber func to override
        void execute(Bureaucrat const& executor) const;// override

    private:
        std::string _target;
};

#endif