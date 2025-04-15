#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

//Derived Concrete class 
class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(PresidentialPardonForm& other);
        PresidentialPardonForm(std::string _target);
        ~PresidentialPardonForm();

        //memeber func to override
        void execute(Bureaucrat const& executor) const;
    
};

#endif 

/*PRESIDENTIALPARDONFORM RULES
- Required grades: sign 25, exec 5
- Informs that <target> has been pardoned by Zaphod Beeblebrox
- take only one parameter in their constructor: the target of the form
*/