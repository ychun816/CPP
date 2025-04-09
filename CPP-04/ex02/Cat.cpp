#include "Cat.hpp"

//con-de structs
Cat::Cat() : AAnimal("🐈"), _brain(new Brain())
{
    std::cout << "Default Cat " << _type << " is created" << std::endl;
}

//construct with type
Cat::Cat(std::string type) : AAnimal(type), _brain(new Brain())
{
    std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete _brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Cat " << _type << " has been assigned!" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat " << _type << " is destroyed" << std::endl;
    delete _brain; // Free the memory allocated for Brain
}

//getter
Brain* Cat::getBrain() const {return (_brain);}


//member funcs
//make sound
void Cat::makeSound(void) const
{
    std::cout << "Cat " << _type << " makes sound: Meow~~~" << std::endl;
}

//tell idea
void Cat::tellIdea(void) const
{
	std::cout << this->_brain->getIdea(42) << std::endl;
}

