#include "Animal.hpp"

//con-de structs
Animal::Animal() : _type("DEFAULT")//default construct
{
    std::cout << "Animal " << _type << " is created" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)//copy->preferred way in C++
{
    // *this = other;//_type = other._type;  // Manually copying the member variable
    std::cout << "Animal " << _type << " has been copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other)//assign operator
{
    if (this != &other)
        _type = other._type;
    std::cout << "Animal " << _type << " has been assigned" << std::endl;
    return (*this);
}

Animal::~Animal()//destruc -> virtual only put in header 
{
    std::cout << "Animal " << _type << " is destroyed" << std::endl;
}

//funcs
void Animal::makeSound(void) const
{
    std::cout << "Animal " << _type << " makes a sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}