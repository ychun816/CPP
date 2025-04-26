#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>     //push(), pop(), top(), empty(), size()
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
   public:
        //syntax : "Define iterator as a shorthand for the iterator/const_iterator type of the container used by std::stack<T>.
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        ////CONSTRUCTORS & DESTURCTOR
        MutantStack();
        MutantStack(const MutantStack& src);
        MutantStack &operator=(const MutantStack& src);
        ~MutantStack();
    
        ////MEMBER FUNCS -ITERATORS
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

#include "MutantStack.tpp"


#endif 


/* NOTES:

//std::stack is a container adaptor, not a real container
//std::stack is a wrapper that gives a stack-like interface (LIFO: last in, first out).
//Internally, it uses another container (default: std::deque) called c
//This is protected, but accessible if you inherit from std::stack
//To make MutantStack iterable -> must access the iterator types of that internal container
//container_type: a typedef inside std::stack that refers to the type of the underlying container


// typename std::stack<T>::container_type::iterator

std::stack<T> : the stack class templated with type T.

container_type : a typedef inside std::stack that refers to the type of the underlying container.
(Usually this is std::deque<T> unless otherwise specified.)

::iterator: this accesses the iterator type of the container_type (which is usually std::deque<T>::iterator).

typename: this is necessary because container_type::iterator is a dependent type — it depends on the template parameter T.
(In C++98 and later, you must use typename to tell the compiler this is a type, not a static value or function)


// MutantStack::iterator and const_iterator
iterator       : Read/Write	-> Used when You want to change elements while looping
const_iterator : Read-only	-> Used when You want to read from a const container or enforce immutability


*/