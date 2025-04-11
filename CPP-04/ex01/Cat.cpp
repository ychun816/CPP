#include "Cat.hpp"

////con-de structs
Cat::Cat() : Animal("🐈"), _brain(new Brain())
{
    std::cout << "Default Cat " << _type << " is created" << std::endl;
}

Cat::Cat(std::string type) : Animal(type), _brain(new Brain())
{
    std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Cat " << _type << " has been assigned!" << std::endl;
    return (*this);
}

//DESTRUCTOR
//Remember to delete the Brain pointer!!
Cat::~Cat()
{
    std::cout << "Cat " << _type << " is destroyed" << std::endl;
    delete _brain;
}

////getter
Brain* Cat::getBrain() const {return (_brain);}


////member funcs
void Cat::makeSound(void) const
{
    std::cout << "Cat " << _type << " makes sound: Meow~~~" << std::endl;
}

void Cat::tellIdea(void) const
{
	std::cout << this->_brain->getIdea(42) << std::endl;
}

