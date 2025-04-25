#include "Array.hpp"

////CONSTRUCTORS & DESTRUCTOR
template <typename T>
Array<T>::Array() : array(NULL), arrayLen(0) {}

//constructor with arrayLen
//[] : allocate WHOLE array (for new & delete)
//must have '()' -> init vlaue (0,0,0)
template <typename T>
Array<T>::Array(unsigned int len) : arrayLen(len)
{
    array = new T[arrayLen]();
}

//copy constructor
//after allocate space => must loop to manually assign value to each element!!
template <typename T>
Array<T>::Array(const Array<T>& src) : arrayLen(src.arrayLen) 
{
    array = new T[arrayLen];
    for (unsigned int i = 0; i < arrayLen; i++)
        array[i] = src.array[i];
}

//assignment operator
// 1 MUST free old existing arrays (no long accessble) -> otherwise cause memory leak (pointer to old array still exist)
// 2 allocate new array with src size -> know size first, know how much space to allocate
// 3 allocate space for new array
// 4 loop through the old array and copy each element to the new array 
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src)
{
    if (this != &src)
    {
        delete[] array;
        arrayLen = src.arrayLen;
        array = new T[arrayLen];
        for (unsigned int i = 0; i < arrayLen; i++)
            array[i] = src.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
    array = NULL;
}


////MEMBER FUNCS
//getter //arraySize
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
