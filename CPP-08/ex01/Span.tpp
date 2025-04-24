#include "Span.hpp"

//constructor & destructor
template <typename T>
Span<T>::Span() : _N(0) { _vec.reserve(0);}

template <typename T>
Span<T>::Span(unsigned int N) : _N(N)
{
    if (N == 0)
        throw std::length_error("Span size cannot be zero");
    // _vec = _vec.reserve(N);
    _vec.reserve(N);//std::vector::reserve() returns void, not a vector.
}

template <typename T>
Span<T>::Span(const Span& src) : _N(src._N), _vec(src._vec){}

template <typename T>
Span<T>& Span<T>::operator=(const Span<T>& src)
{
    if (this != &src)
    {
        _N = src._N;
        _vec = src._vec;
    }
    return *this;
}

template <typename T>
Span<T>::~Span(){}


////member funcs
//add nb
//If _vec.size() >= _N -> throw exception
//.push_back() -> to add the number to the vector
template <typename T>
void Span<T>::addNumber(T n)
{
    if (_vec.size() >= _N)
        throw std::length_error("Span is full!");
    _vec.push_back(n);

    // std::cout << "Added Number: " << n << std::endl;
    // std::cout << "Current Vector Size: " << _vec.size() << std::endl;
}

//shorest span
//If _vec.size() < 2 -> not enough nbs -> throw exception
//Copy and sort _vec -> sort(_vec.begin(), _vec.end()); / 
//Loop to find the smallest span => @NOTE!! avoid go outa bound => order [latter] - [former] 
//std::numeric_limits<int>::max() -> give the largest value an int can represent (2147483647)!!!
template <typename T>
int Span<T>::shortestSpan() const
{
    if (_vec.size() < 2)
        throw std::length_error("Not enough elements to find a shortest span");

    std::vector<int> sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    T intMAX = std::numeric_limits<T>::max();

    for (size_t i = 1; i < sortedVec.size() - 1; i++) //init i frm [latter] to avoid go outa bound
    {
        T span = sortedVec[i] - sortedVec[i - 1];
        if (span < intMAX)//span will be always smaller than intMAX -> enter loop & updae intMAX value
            intMAX = span;
    }
    std::cout << "The smallest span: [ " << intMAX << " ]" << std::endl;
    return intMAX;
} 


//longest span
//If _vec.size() < 2 -> not enough nbs -> throw exception
//Copy and sort _vec
//Return max - min from _vec

/** template <typename ForwardIterator>
 * @note ForwardIterator min_element(ForwardIterator first, ForwardIterator last);
 * @note ForwardIterator max_element(ForwardIterator first, ForwardIterator last);
 * 
 * @note  an iterator is an object that points to an element in a container (such as an array, vector, list, etc.), allowing you to traverse and access the elements within the container.
 * @note Why Use *?
 * -> dereference operator(*) => you don't get the value itself, but instead, you get a pointer to the value (i.e., an iterator pointing to that element)
 */
template <typename T>
int Span<T>::longestSpan() const
{
    if (_vec.size() < 2)
        throw std::length_error("Not enough elements to find a longest span");
    
    std::vector<int> sortedVec = _vec;
    T minValue = *std::min_element(sortedVec.begin(), sortedVec.end());
    T maxValue = *std::max_element(sortedVec.begin(), sortedVec.end());
    // std::vector<int> maxSpan = maxValue - minValue;
    std::cout << "The longest span: [ " << maxValue - minValue << " ]"<< std::endl;
    
    return (maxValue - minValue);
}
