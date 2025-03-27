#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat ();//default construct
        WrongCat (WrongCat & other);//copy
        WrongCat  operator=(WrongCat & other);//assign operator
        ~WrongCat ();//destruc
        
};

#endif