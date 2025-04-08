#include "Dog.hpp"

//con-de structs
Dog::Dog()
{
    _type = "🐕";
    std::cout << "Dog " << _type << " is created" << std::endl;
}

// Explicitly call base class copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
    _type = other._type;
    std::cout << "Dog " << _type << " has been copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other); // Ensure the base class data is copied properly    
    std::cout << "Dog " << _type << " has been assigned!" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog " << _type << " is destroyed" << std::endl;
}

//member funcs
void Dog::makeSound(void) const
{
    std::cout << "Dog " << _type << " makes sound: Woof! Woof!!" << std::endl;
}