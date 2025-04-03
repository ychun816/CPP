#include "ShrubberyCreationForm.hpp"


//con/de-structors
ShrubberyCreationForm::ShrubberyCreationForm() : _target("")//default
{
    std:: cout << "--- ShrubberyCreationForm default constructor called ---" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)//copy
{
    _target = other._target;
    // std::cout << "--- ShrubberyCreationForm " << " is copied ---" << std::endl;
    std::cout << "--- ShrubberyCreationForm " << _target << " is copied ---" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)//assign
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    // std::cout << "--- ShrubberyCreationForm " << " is assigned ---" << std::endl;
    std::cout << "--- ShrubberyCreationForm " << _target << " is assigned ---" << std::endl;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)//init with name and grade
{
    this->_target = target;
    std:: cout << "--- ShrubberyCreationForm with target [" << _target << "] is created ---" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()//destructor
{
    std:: cout << "--- ShrubberyCreationForm default destructor called ---" << std::endl;
    // std:: cout << "--- ShrubberyCreationForm " << _name << " is destroyed ---" << std::endl;
}

//MEMBER FUNS 
//execute
//create file
//open+write ascii tree inside
//close

/**
 * @note 
 * std::ofstream in C++98 expects a const char* (C-style string)!!
 * alling the c_str() method on the string!! 
 * 
 * @note std::ofstream file(target + "_shrubbery")
 * is an output file stream, used to create and write to files
 * file(target + "_shrubbery") creates a file named <target>_shrubbery in the current working directory.
 * @note file << "🌳 ASCII TREE 🌳\n";
 * file << writes the given text into the file
 */
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    (void)executor;
    //if cannot signed&execute cases frm AForm
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