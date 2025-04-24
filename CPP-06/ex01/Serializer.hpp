#ifndef Serializer_HPP
#define Serializer_HPP
#pragma once

#include "Data.hpp"

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

//utility class -> set constructor&destructor private -> prevent instantiation
//static methods -> set member funcs "static" -> Functions that belong to a class but not to an object -> access without instantiation
class Serializer
{
    private:
        Serializer();
        ~Serializer();
    
    public:
        ////member funcs
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif


/* NOTES: 

//Reinterpret_Cast
-> doesn't check safety, but it does powerful conversions(forcefully)!
- Pointer ↔ integer conversions
- One pointer type ↔ another pointer type (like void* ↔ int*)
- Raw memory reinterpretation

//uintptr_t 
-> an unsigned integer type that is guaranteed to be able to hold a pointer value.
-> allows converting a pointer to an integer, or vice versa, safely and portably.

//Type casting
-> Change a variable from one type to another

*/