#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <limits>     // For INT_MAX in shortestSpan()

template <typename T>
class Span
{
    private:
        unsigned int _N;
        std::vector<T> _vec;

    public:
        Span();// Optional, may be omitted if not used
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        //member funcs
        void addNumber(T n);
        int shortestSpan() const; 
        int longestSpan() const;

        //FOR TEST 10000
        size_t getVectorSize() const { return _vec.size(); }

};

// Test your Span with at least 10,000 numbers.

#include "Span.tpp"


#endif 