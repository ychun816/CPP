#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), arrayLen(0) {}

//must have '()' -> initialize value (0, 0, 0)
template <typename T>
Array<T>::Array(unsigned int len) : arrayLen(len)
{
    array = new T[arrayLen](); //[]-> allocate whole array
    // for (unsigned int i = 0; i < len; i++)
    //     array[i] = T();
}

//copy constructor
//new T[arraySize]; already calls the default constructor of each element.
//after allocate => must loop to manually assign value to each element
//Immediately after, you're overwriting every element with other.array[i].
template <typename T>
Array<T>::Array(const Array<T>& src) : arrayLen(src.arrayLen) 
{
    array = new T[arrayLen];
    for (unsigned int i = 0; i < arrayLen; i++)
        array[i] = src.array[i];
}

//assignment operator
//delete[] / new[] => for arrays!
//must delete[]
//The old array is still in memory but no longer accessible -> must free it before!!
//-> array = new T[arraySize]; would overwrite the pointer, losing the link to previously allocated memory.
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src)
{
    if (this != &src)
    {
        delete[] array; // Free the existing arrays! []
        arrayLen = src.arrayLen; // Copy the array len
        array = new T[arrayLen]; // Allocate new memory
        for (unsigned int i = 0; i < arrayLen; i++)
            array[i] = src.array[i]; // Copy the elements
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
    array = NULL;
}

//getter 
//arraySize
template <typename T>
unsigned int Array<T>::size() const { return (arrayLen);}

//operator []
template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
    if (index >= arrayLen)
        throw std::out_of_range("Index out of range");
    return (array[index]);
}