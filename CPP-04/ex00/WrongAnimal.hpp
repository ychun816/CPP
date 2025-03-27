#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

// #include "WrongCat.hpp"//CANNOT INCLUDE!
#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();//default construct
        WrongAnimal(const WrongAnimal& other);//copy
        WrongAnimal& operator=(const WrongAnimal& other);//assign operator
        virtual ~WrongAnimal();//destruc

    	void makeSound() const;// Non-virtual, no polymorphism
        std::string getType() const;
};

#endif