#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();//default construct
        Dog(Dog& other);//copy
        Dog operator=(Dog& other);//assign operator
        ~Dog();//destruc
    
    
};

#endif