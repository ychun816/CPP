#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <limits>    //INT_MAX in shortestSpan()

template <typename T>
class Span
{
    private:
        unsigned int _N;
        std::vector<T> _vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        ////MEMBER FUNCS
        void addNumber(T n);
        int shortestSpan() const; 
        int longestSpan() const;

        //FOR TEST 10000
        size_t getVectorSize() const { return _vec.size(); }

};

#include "Span.tpp"

#endif 