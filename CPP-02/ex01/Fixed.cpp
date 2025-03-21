#include "fixed.hpp"

////CONSTRUCTOR
//default
Fixed::Fixed():_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//int
// Multiply by 2^8 => << frationalBits
Fixed::Fixed(const int intValue)
{
    _value = _value << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

//float
//use roundf() to get proximate int
//roundf(floatValue * (1 << _fractionalBits) => roundf(floatValue * 256)

Fixed::Fixed(const float floatValue)
{
    _value = _value * (1 << _fractionalBits);
    std::cout << "Float constructor called" << std::endl;
}

//destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

////copy constructor
Fixed:: Fixed()
{
    std::cout << "Copy constructor called" << std::endl;
}

////assignment operator
Fixed& operator=(const Fixed& other)
{
    if (this != &other)
        this->_value = this->getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

////RAW BITS
void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

int Fixed::getRawBits( void ) const
{
    return (this->_value);
}

////CONVERTER
float toFloat( void ) const
{

}

int toInt( void ) const
{

}