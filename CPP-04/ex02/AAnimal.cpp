#include "AAnimal.hpp"

//con-de structs
AAnimal::AAnimal() : _type("DEFAULT")
{
    std::cout << "Default AAnimal is created" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal " << _type << " is created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
    std::cout << "AAnimal " << _type << " has been copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "AAnimal " << _type << " has been assigned" << std::endl;
    return (*this);
}

//destructor
//virtual only put in header 
AAnimal::~AAnimal()
{
    std::cout << "AAnimal " << _type << " is destroyed" << std::endl;
}

//getter 
std::string AAnimal::getType(void) const {return (_type);}

//member funcs
void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal " << _type << " makes a sound" << std::endl;
}

void AAnimal::tellIdea(void) const
{
    std::cout << "AAnimal " << _type << " tell an idea" << std::endl;
}
