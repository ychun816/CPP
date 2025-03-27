#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("DEFAULT-W")//default construct
{
    std::cout << "default WrongAnimal " <<  _type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) :  _type(other._type)//copy
{
    std::cout << "WrongAnimal " <<  _type << " has been copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)//assign operator
{
    if (this != &other)
        _type = other._type;
    std::cout << "WrongAnimal " <<  _type << " has been assigned" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()//destruc
{
    std::cout << "WrongAnimal " <<  _type << " is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const// Non-virtual, no polymorphism
{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}
