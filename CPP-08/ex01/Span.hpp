#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

template <typename T>
class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        //member funcs
        void addNumber(int n);
        Span& shortestSpan() const; 
        Span& longestSpan() const;

};

// Test your Span with at least 10,000 numbers.



#endif 