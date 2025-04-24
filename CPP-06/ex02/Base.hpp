#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>  //std::rand()
#include <ctime>    //std::srand(std::time(nullptr)

//Abstract Base class -> cannot be instantiated
//Ensure Base class is polymorphic -> has a virtual destructor
class Base
{
    public:
        // Base();
        virtual ~Base();

        ////member funcs
        static Base* generate();
        static void identify(Base* p);//poinnter
        static void identify(Base& p);//reference -> need exception handling
};
    
#endif


/* NOTES:

//IMPLEMENT STEPS:
1. create abstract base class Base
2. create derived classes A/B/C
3. generate() in Base -> create random instances of A/B/C
4. identify() in Base -> identify the type of the object


//Polymorphism : using a base class pointer or reference to access derived class objects

//Dynamic Cast
-> safely casting base class pointers or references to derived class types.
-> Dynamic_cast works only on polymorphic classes (i.e., classes with at least one virtual function).
-> It allows safe downcasting from base to derived.

- When using a pointer -> it returns nullptr on failure.
- When using a reference -> it throws a std::bad_cast on failure.


//static void identify(Base* p) : Clean, fast, and doesn't throw exceptions (cuz pointer -> can return NULL)
//static void identify(Base& p) : Use exception handling with reference casts (cuz reference -> cannot return NULL, always point to an object(address))

*/