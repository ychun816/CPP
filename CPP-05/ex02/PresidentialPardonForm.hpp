#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

//Required grades: sign 25, exec 5
//Informs that <target> has been pardoned by Zaphod Beeblebrox.
// take only one parameter in their constructor: the target of the form
class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();//default
        PresidentialPardonForm(PresidentialPardonForm& other);//copy
        PresidentialPardonForm& operator=(PresidentialPardonForm& other);//assign
        PresidentialPardonForm(std::string _target);//init with name and grade
        ~PresidentialPardonForm();//destructor

        //memeber func to override
        void execute(Bureaucrat const& executor) const;// override
    
    private:
        std::string _target;
};


#endif 