#include "Dog.hpp"

//con-de structs
Dog::Dog() : brain(new Brain)//default construct
{
    _type = "🐕";
    std::cout << "Dog " << _type << " is created" << std::endl;
}

Dog::Dog(const Dog& other) : brain(new Brain(*other.brain)) // Explicitly call base class copy constructor//_type(other._type) //copy
{
    // _type = other._type;
    //*this = other;  // Manually copying the member variable
    std::cout << "Dog " << _type << " has been copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other)//assign operator
{
    if (this != &other)
    {
        Animal::operator=(other); // Ensure the base class data is copied properly    
        *this->brain = *other.brain;
        // _type = other._type;
    }
    std::cout << "Dog " << _type << " has been assigned!" << std::endl;
    return (*this);
}

Dog::~Dog()//destruc
{
    std::cout << "Dog " << _type << " is destroyed" << std::endl;
    delete (brain);//why delete here?
}

//funcs
void Dog::makeSound(void) const
{
    std::cout << "Dog " << _type << " makes sound: Woof! Woof!!" << std::endl;
}

//brain
Brain *Dog::getBrain(void) const
{
    return brain;
}
