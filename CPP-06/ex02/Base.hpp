#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>  //std::rand()
#include <ctime>    //std::srand(std::time(nullptr)

//To use dsynamic_cast -> common practice -> virtual destructor in base class
//virtual enables polymorphism, not abstraction
class Base
{
    public:
        virtual ~Base();

        ////member funcs
        static Base* generate();
        static void identify(Base* p);//pointer
        static void identify(Base& p);//reference
};
    
#endif


/* NOTES:

//Polymorphism : using a base class pointer or reference to access derived class objects

//Dynamic_Cast
-> safely casting base class pointers or references to derived class types.
-> It allows safe downcasting from base to derived.
-> Dynamic_cast works ONLY on POLYMORPHIC CLASSES!! (i.e., classes with AT LEAST one virtual function!!) -> This makes the class polymorphic, enabling runtime type identification (RTTI).
-> In practice, this is often the virtual destructor!!

//static void identify(Base* p) (pointer)
-> Clean, fast, and doesn't throw exceptions (cuz pointer -> can return NULL)

//static void identify(Base& p) (reference)
-> Use exception handling with reference casts (cuz reference -> cannot return NULL, always point to an object(address))
-> Used when you know the reference is valid, and you need exact type checking

*/