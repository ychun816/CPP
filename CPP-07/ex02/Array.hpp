#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

//template class -> work with any data type 'T'
//he `<T>` after `Array` tells the compiler: *“Use `T` for this specific instantiation of the template.”*
template <typename T>
class Array
{
    private:
        T* array;// Pointer to the array of type T
        size_t arrayLen;// Size of the array

    public:
        Array();
        Array(unsigned int len);
        Array(const Array& src);
        Array &operator=(const Array& src);
        ~Array();

        ////MEMBER FUNCS
        //getter
        unsigned int size() const;
        
        //operator[]
        T& operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif 