#include "MutantStack.hpp"


// typedef typename std::stack<T>::container_type::iterator iterator;
// typedef typename std::stack<T>::container_type::const_iterator const_iterator;

//CONSTRUCTORS & DESTRUCTOR
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>(src){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src)
{
    if (this != &src)
        std::stack<T>::operator=(src);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}


//MEMBER FUNCS -ITERATORS
//typedef typename std::stack<T>::container_type::iterator iterator;


//iterator
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin(); //use this-> to help name lookup
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

//const_iterator
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}