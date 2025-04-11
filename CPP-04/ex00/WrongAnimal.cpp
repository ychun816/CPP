#include "WrongAnimal.hpp"

////constructor & destructor
WrongAnimal::WrongAnimal() : _type("DEFAULT-W")
{
    std::cout << "default WrongAnimal " <<  _type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) :  _type(other._type)
{
    std::cout << "WrongAnimal " <<  _type << " has been copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "WrongAnimal " <<  _type << " has been assigned" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " <<  _type << " is destroyed" << std::endl;
}

////getter
std::string WrongAnimal::getType() const{return (_type);}

////member func
// Non-virtual, no polymorphism
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}

