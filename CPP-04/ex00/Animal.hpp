#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();//default construct
        Animal(Animal& other);//copy
        Animal operator=(Animal& other);//assign operator
        ~Animal();//destruc
    
};

#endif