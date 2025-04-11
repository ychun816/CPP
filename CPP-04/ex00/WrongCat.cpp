#include "WrongCat.hpp"

////constructs & destructors
WrongCat::WrongCat()
{
    _type = "😾";
    std::cout << "WrongCat " <<  _type << " is created" <<std::endl;
}

//copy constructor
//Any additional members in WrongAnimal are properly initialized
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    _type = other._type;
    std::cout << "WrongCat " <<  _type << " has been copied" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)//assign operator
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);// Ensure the base class data is copied properly        
        _type = other._type;
    }
    std::cout << "WrongCat" <<  _type << " has been assigned" <<std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat" <<  _type << " is destroyed" <<std::endl;
}


////member funcs
void WrongCat::makeSound(void) const
{
    std::cout << "MEOWOWOWOW!!!!!" <<std::endl;
}