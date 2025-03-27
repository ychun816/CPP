#include "Dog.hpp"

//con-de structs
Dog::Dog()//default construct
{
    _type = "defaultDog";
    std::cout << "Dog " << _type << " is created" << std::endl;
}
Dog::Dog(const Dog& other) //Animal(other)  // Explicitly call base class copy constructor//_type(other._type) //copy
{
    *this = other;//_type = other._type;  // Manually copying the member variable
    std::cout << "Dog " << _type << " has been copied" << std::endl;
}
Dog& Dog::operator=(const Dog& other)//assign operator
{
    if (this != &other)
        Animal::operator=(other); // Ensure the base class data is copied properly    
        // _type = other._type;
    std::cout << "Dog " << _type << " has been assigned!" << std::endl;
    return (*this);
}
Dog::~Dog()//destruc
{
    std::cout << "Dog is destroyed" << std::endl;
}

//funcs
void Dog::makeSound(void) const
{
    std::cout << "Dog makes sound: Woof! Woof! Woof!" << std::endl;
}