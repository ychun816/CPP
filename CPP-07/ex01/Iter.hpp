#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

//pass a function as a parameter to another function
//pass template functions to another template

//IMPLEMENT STEPS:
//Implement iter() as a function template.
//Create a print() function template.
//Test with arrays of: int / float / std::string

//iter
template <typename T, typename Function>
void iter(T *array, int len, Function func)//(T &)
{
    if (len <= 0)
        return ;
    for (int i = 0; i < len; i++)
    {
        func(array[i]);
    }
}

//print
// print() is a function template!! not "a function" that takes a reference to a variable of type T
//value is a reference to a variable of type T
//You’re not copying the value, and you can modify it if needed
// use references unless you specifically need pointers -> 
template <typename T>
void print(const T &value)
{
    std::cout << value << std::endl;
}

//checkeven
template <typename T>
void checkEven(const T &value)
{
    (value % 2 == 0) ? std::cout << value << " is even\n" : std::cout << value << " is odd\n";
}

//multiply
template <typename T>
void multiplyTWO(const T &value)
{
    std::cout << value * 2 << std::endl;
}

// // Multiply functor template
// template <typename T>
// struct Multiply 
//{
//     int factor;
//     Multiply(int factor) : factor(factor) {}
//     void operator()(T &element) {
//         element *= factor;  // Multiply the element by the factor
//     }
// };



#endif 

/* NOTES

template <typename T> :	Write generic functions that work with any type

Function pointers : Pass a function as a parameter (void (*func)(T&))

Arrays and pointer decay : Understand how arrays are passed to functions

Reference types (T &) : Allow modifications to array elements in-place

Reusability	: Separate logic into .hpp, test in main.cpp, and compile via Makefile

Function template as arg : Use a templated function like print<T>() as a callback

*/


/*

Concept     | Analogy                        | Code
---------------------------------------------------
Reference   | A nickname                     | T &x
Pointer     | A phone number                 | T *x
Dereference | Call the phone (get the value) | *x


T *array          :	Pointer to first element of array of type T
T &x	          : Reference to a T (no copy, can modify original)
void (*func)(T &) :	Function pointer taking reference to T and returning void!
void print(T &x)  :	Function taking reference to T and printing or modifying it

*/