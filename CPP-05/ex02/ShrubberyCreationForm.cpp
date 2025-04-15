#include "ShrubberyCreationForm.hpp"


////CONSTRUCTOR & DESTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("DEFAULT")
{
    std:: cout << "--- ShrubberyCreationForm default constructor called ---" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(), _target(other._target)
{
    // _target = other._target;
    std::cout << "--- ShrubberyCreationForm Copy Constructor called ---" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
    if (this != &other)
        this->_target = other._target;
    std::cout << "--- ShrubberyCreationForm Assign Operator called ---" << std::endl;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    // this->_target = target;
    std:: cout << "--- ShrubberyCreationForm with target [ " << _target << " ] is created ---" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std:: cout << "--- ShrubberyCreationForm default destructor called ---" << std::endl;
}

//MEMBER FUNS 
/** //execute
 * (1) create file / (2) open+write ascii tree inside / (3) close
 * 
 * @note .c_str()
 * -> std::ofstream in C++98 expects a const char* (C-style string)!!
 * -> alling the c_str() method on the string!! 
 * 
 * @note std::ofstream file(target + "_shrubbery")
 * -> an output file stream, used to create and write to files
 * -> file(target + "_shrubbery") creates a file named <target>_shrubbery in the current working directory.
 * @note file << "🌳 ASCII TREE 🌳\n";
 * -> file << writes the given text into the file
 */
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    (void)executor;//put void?

    std::ofstream filename((_target + "_shrubbery").c_str());
    if (!filename)
    {
        std::cerr << "Error : Cannot create file" << std::endl;
        // return;
    }
    else
    {
        filename << "🌳 ASCII TREE 🌳" << std::endl << std::endl;
        filename << "       /\\" << std::endl;
        filename << "      /  \\" << std::endl;
        filename << "     /____\\" << std::endl;
        filename << "       ||" << std::endl << std::endl;
    }
    filename.close();
}