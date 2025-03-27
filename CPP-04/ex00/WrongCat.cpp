#include "WrongCat.hpp"

WrongCat::WrongCat()//default construct
{
    _type = "😾";
    std::cout << "WrongCat " <<  _type << " is created" <<std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)//copy //Any additional members in WrongAnimal are properly initialized
{
    _type = other._type;
    std::cout << "WrongCat " <<  _type << " has been copied" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)//assign operator
{
    if (this != &other)
        WrongAnimal::operator=(other);// Ensure the base class data is copied properly        
        // _type = other._type;
    std::cout << "WrongCat" <<  _type << " has been assigned" <<std::endl;
    return (*this);
}

WrongCat::~WrongCat()//destruc
{
    std::cout << "WrongCat" <<  _type << " is destroyed" <<std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "MEOWOWOWOW!!!!!" <<std::endl;
}