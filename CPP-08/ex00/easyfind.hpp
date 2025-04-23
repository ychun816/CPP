#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>// for std::find
#include <iterator> // for iterator
#include <vector> //for std::vector
#include <list> //for std::list

// Accepts any container of integers
// Searches for the first occurrence of a given integer
// Returns an iterator to the element if found
// Throws an exception if the value is not found

/** NOTE
 * @note std::find(vec.begin(), vec.end(), 30) 
 * -> searches from the beginning of the vector to the end for the value 30.
 * @note .begin()
 * -> Returns an iterator pointing to the first element of the container
 * @note .end()
 * -> Returns an iterator pointing just past the last element of the container
*/


template <typename T>
typename T::iterator easyfind(T& container, int value)//search for the certian value
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in the container 🪤");
    return it;
}


#endif 