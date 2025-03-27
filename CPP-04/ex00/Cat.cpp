#include "Cat.hpp"

//con-de structs
Cat::Cat()//default construct
{
    _type = "🐈";
    std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) // Properly call base class copy constructor
{
    _type = other._type;
    std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)  // Correct assignment operator
{
    if (this != &other)
        Animal::operator=(other);  // Call base class assignment
    std::cout << "Cat " << _type << " has been assigned!" << std::endl;
    return (*this);
}

Cat::~Cat()//destruc
{
    std::cout << "Cat " << _type << " is destroyed" << std::endl;
}

//funcs
void Cat::makeSound(void) const
{
    std::cout << "Cat " << _type << " makes sound: Meow~~~" << std::endl;
}