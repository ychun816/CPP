#include "Intern.hpp"

//constructor & destructor
Intern::Intern()
{
    std:: cout << "--- Intern Constructor called ---" << std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
    std:: cout << "--- Intern Copy Constructor called ---" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
        *this = other;
    std:: cout << "--- Intern Assign Operator called ---" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std:: cout << "--- Intern Destructor called ---" << std::endl;
}


////MEMBER FUNCS
//makeForm
//It returns a pointer to a AForm object (corresponding to the form name passed as a parameter)
//with its target initialized to the second parameter

AForm& Intern::makeForm(std::string formName, std::string target)
{
    //1 Function Pointer Array!!
    //holds pointers to factory functions that each return an AForm*
    //Each function: AForm* createRobotomyRequest(std::string& target);
    AForm* (*formCreator[3])(std::string&) = 
    {
        createShrubberyCreation,
        createRobotomyRequest,
        createPresidentialForm,
    };

    //2 Form Name Array
    //An array of strings that lists all valid form names
    //These strings map 1-to-1 with the function pointers in formCreator
    const std::string forms[3] =
    {
        "shrubbery creation",
        "robotomy request",
        "presidential form",
    };

    //3 Loop to Find Matching Form -> print msg "Intern creates <formName> form"
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (*formCreator[i](target));
        }
    }
    throw WrongFormNameException();//if not found form name
}