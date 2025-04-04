#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

// #include "Cat.hpp"//Animal is base class!! CANNOT include subtype!
// #include "Dog.hpp"//CANNOT INCLUDE!!-> circular dependancy WRONG!

//BASE CLASS
//@note
//The base class destructor in C++ needs to be virtual when you have a class hierarchy with polymorphism
//If the destructor in the base class Animal is not virtual, the base class destructor (Animal::~Animal) is called, and the destructor of the derived class (Cat::~Cat) is not called.
//lead to resource leaks, because the derived class might have allocated resources (e.g., memory, file handles, etc.) that are not cleaned up when the base class destructor is invoked.
class Animal 
{
    protected:
        std::string _type;

    public:
        Animal();//default construct
        Animal(const Animal& other);//copy
        Animal& operator=(const Animal& other);//assign operator
        virtual ~Animal();//destruc
    
        virtual void makeSound(void) const;
        std::string getType(void) const;
};

#endif
