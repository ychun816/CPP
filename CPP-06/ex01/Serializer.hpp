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

// Private constructor to prevent instantiation
//Classes that can’t be instantiated: Preventing users from creating an object of a class
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
// reinterpret_cast
=> doesn't check safety, but it lets you do powerful conversions!
- Pointer ↔ integer conversions
- One pointer type ↔ another pointer type (like void* ↔ int*)
- Raw memory reinterpretation

//Type casting: Changing a variable from one type to another

//Static methods: Functions that belong to a class but not to an object.

//uintptr_t: An unsigned integer type that can safely hold a pointer as a number.
*/