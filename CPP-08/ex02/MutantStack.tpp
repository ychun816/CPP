#include "MutantStack.hpp"

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
//this -> help to access the protected member c of std::stack<T>
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
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