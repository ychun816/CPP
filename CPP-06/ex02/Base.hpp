#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding time

/*
Polymorphism — using a base class pointer or reference to access derived class objects.
Dynamic Casting — safely casting base class pointers or references to derived class types.
Runtime Behavior — identifying object types dynamically at runtime without relying on typeid

dynamic_cast works only on polymorphic classes (i.e., classes with at least one virtual function).
It allows safe downcasting from base to derived.
When using a pointer, it returns nullptr on failure.
When using a reference, it throws a std::bad_cast on failure.

IMPLEMENT STEPS:
1. create abstract base class Base
2. create derived classes A/B/C
3. generate() in Base -> create random instances of A/B/C
4. identify() in Base -> identify the type of the object
*/

//Abstract Base class -> cannot be instantiated
//suggested use non static member funcs
class Base
{
    public:
        // Base();
        virtual ~Base();

        //member funcs
        static Base* generate();
        static void identify(Base* p);//clean, fast, and doesn't throw exceptions
        static void identify(Base& p);//use exception handling with reference casts
};
    

#endif