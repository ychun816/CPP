#ifndef Serializer_HPP
#define Serializer_HPP
#pragma once

#include "Data.hpp"
#include <iostream>
#include <cstdint> // for uintptr_t

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
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif