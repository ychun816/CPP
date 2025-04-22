#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

//swap
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

//min
template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

//max
template <typename T>
const T& max(const T& a, const T& b)
{
    return (a > b ? a : b);
}


#endif 


/* NOTES
define a template function
every template function must be preceded by its own template <typename T> declaration!
Each function must be prefixed with 'the template'
If working with template classes -> can write the template <typename T> just once before the class definition, and all methods inside will use the same type.

template<...> tells the compiler: “I’m about to define a template function or class.”
typename T means: “T is a placeholder for a data type (like int, float, string, etc).”
T is not a real type — it's a symbol you define
When you call the function, the compiler figures out what T should be based on the argument types.
!!! Using const T& avoids unnecessary copying (If T is a large object, copying it directly is slow and wasteful)

Q: Why use references (&)?
T &a means pass by reference, not by value.
If you just used T a, it would make a copy, and any change to a would only affect the copy.
*/