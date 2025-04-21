#ifndef Serializer_HPP
#define Serializer_HPP
#pragma once

#include "Data.hpp"

#include <stdint.h> // uintptr_t ??
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

//practice reinterpret_cast!
//Type casting: Changing a variable from one type to another
//Static methods: Functions that belong to a class but not to an object.
//Classes that can’t be instantiated: Preventing users from creating an object of a class.
//uintptr_t: An unsigned integer type that can safely hold a pointer as a number.
class Serializer
{
    // Private constructor to prevent instantiation
    private:
        Serializer();
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif


/*
reinterpret_cast is for:
- Pointer ↔ integer conversions
- One pointer type ↔ another pointer type (like void* ↔ int*)
- Raw memory reinterpretation

It doesn't check safety, but it lets you do powerful conversions, which is exactly what we need here.
*/