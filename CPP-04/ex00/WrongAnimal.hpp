#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"
#include "WrongCat.hpp"

class WrongAnimal : public Animal
{
    public:
        WrongAnimal();//default construct
        WrongAnimal(WrongAnimal& other);//copy
        WrongAnimal operator=(WrongAnimal& other);//assign operator
        ~WrongAnimal();//destruc
    
    
};

#endif