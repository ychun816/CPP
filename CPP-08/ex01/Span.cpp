#include "Span.hpp"

//constructor & destructor
Span::Span() : _N(0)
{
    _vec.reserve(0);
}

Span::Span(unsigned int N) : _N(N)
{
    if (N == 0)
        throw std::length_error("Span size cannot be zero");
    _vec.reserve(N);//? reserve space for N elements?
}

Span::Span(const Span& src) : _N(src._N), _vec(src._vec)
{
}

Span& Span::operator=(const Span& src)
{}

Span::~Span()
{}

//member funcs
void Span::addNumber(int n);

Span& Span::shortestSpan() const; 

Span& Span::longestSpan() const;