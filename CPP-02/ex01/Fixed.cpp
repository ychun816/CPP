#include "Fixed.hpp"

//CONSTRUCTOR & DESTRUCTOR
//default
Fixed::Fixed():_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//copy
Fixed:: Fixed(const Fixed& other)
{
    this->_value = other.getRawBits(); // Copy the value properly
    std::cout << "Copy constructor called" << std::endl;
}

//assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

//init values
/** init int value
 * Multiply by 2^8 => << frationalBits
 */
Fixed::Fixed(const int intValue)
{
    _value = intValue << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

/**init float value
 * use roundf() to get proximate int
 * roundf(floatValue * (1 << _fractionalBits) => roundf(floatValue * 256)
 */
Fixed::Fixed(const float floatValue)
{
    _value =  roundf(floatValue * (1 << _fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}

//destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

////MEMBER FUNCS
void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

int Fixed::getRawBits( void ) const
{
    return (this->_value);
}

//CONVERTER
/** float to fixed-point
 * (1 << _fractionalBits) computes 2^_fractionalBits
 * If _fractionalBits = 8, -> then 1 << 8 = 256
 * _value / 256 converts the fixed-point value to a floating-point number
 */
float Fixed::toFloat( void ) const
{
    return (float) _value / (1 << _fractionalBits);// Divide by 2^8
}

/** int to fixed-point
 * _value >> _fractionalBits is equivalent to _value / (2^_fractionalBits)
 * Divide by 2^8 using bit shift =>  removes the fractional part, converting the number to an integer
 */
int Fixed::toInt( void ) const
{
    return (int) (_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    output << fixed.toFloat();// Convert fixed-point to float for printing
    return (output);
}