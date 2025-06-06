#include "Animal.hpp"

////constructs & destructors
Animal::Animal() : _type("DEFAULT")
{
    std::cout << "Default Animal is created" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal " << _type << " is created" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Animal " << _type << " has been copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "Animal " << _type << " has been assigned" << std::endl;
    return (*this);
}

//destructor
Animal::~Animal()
{
    std::cout << "Animal " << _type << " is destroyed" << std::endl;
}

///getter 
std::string Animal::getType(void) const {return (_type);}

////member funcs
void Animal::makeSound(void) const
{
    std::cout << "Animal " << _type << " makes a sound" << std::endl;
}

void Animal::tellIdea(void) const
{
    std::cout << "Animal " << _type << " tell an idea" << std::endl;
}
