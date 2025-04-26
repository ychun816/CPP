#include "Span.hpp"

////CONSTRUCTORS & DESTURCOTR
//reserve() pre-allocate capacity -> have 0 size! (not change the vector size!!)
//.push_back() : trully allocate elements into vector container -> have actual size!
template <typename T>
Span<T>::Span() : _N(0) { _vec.reserve(0);}

template <typename T>
Span<T>::Span(unsigned int N) : _N(N)
{
    if (N == 0)
        throw std::length_error("Span size cannot be zero");
    _vec.reserve(N);
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


////MEMBER FUNCS
//add number
template <typename T>
void Span<T>::addNumber(T n)
{
    if (_vec.size() >= _N)
        throw std::length_error("Span is full!");
    _vec.push_back(n);
    // std::cout << "Added Number: " << n << std::endl;
    // std::cout << "Current Vector Size: " << _vec.size() << std::endl;
}

/** shorest span
 * 1 If _vec.size() < 2 -> not enough nbs -> throw exception
 * 2 Copy and sort _vec -> sort(_vec.begin(), _vec.end()); / 
 * 3 Loop to find the smallest span => @NOTE!! avoid go outa bound => order [latter] - [former]
 * 
 * @note std::numeric_limits<int>::max() -> give the largest value an int can represent (2147483647)!!!
 * @note init i frm [latter] to avoid go outa bound
 * @note span will be always smaller than intMAX -> enter loop & updae intMAX value! -> find the smallest span!
 */
template <typename T>
int Span<T>::shortestSpan() const
{
    if (_vec.size() < 2)
        throw std::length_error("Not enough elements to find a shortest span");

    std::vector<int> sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    T intMAX = std::numeric_limits<T>::max();

    for (size_t i = 1; i < sortedVec.size() - 1; i++)
    {
        T span = sortedVec[i] - sortedVec[i - 1];
        if (span < intMAX)
            intMAX = span;
    }
    std::cout << "The smallest span: [ " << intMAX << " ]" << std::endl;
    return intMAX;
} 

/** longest span
 * 1 If _vec.size() < 2 -> not enough nbs -> throw exception
 * 2 Copy and sort _vec
 * 3 Return max - min from _vec
 * 
 * //template <typename ForwardIterator>
 * @note ForwardIterator min_element(ForwardIterator first, ForwardIterator last);
 * @note ForwardIterator max_element(ForwardIterator first, ForwardIterator last);
 * @note an iterator is an object that points to an element in a container (such as an array, vector, list, etc.), allowing you to traverse and access the elements within the container.
 * @note dereference operator(*) 
 * -> you don't get the value itself, instead uou get a pointer to the value (i.e., an iterator pointing to that element)
 */
template <typename T>
int Span<T>::longestSpan() const
{
    if (_vec.size() < 2)
        throw std::length_error("Not enough elements to find a longest span");
    
    std::vector<int> sortedVec = _vec;
    T minValue = *std::min_element(sortedVec.begin(), sortedVec.end());
    T maxValue = *std::max_element(sortedVec.begin(), sortedVec.end());
    std::cout << "The longest span: [ " << maxValue - minValue << " ]" << std::endl;
    
    return (maxValue - minValue);
}
