#include "Fixed.hpp"

////CONSTRUCTORS
Fixed::Fixed():_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//int constructor 
Fixed::Fixed(const int intValue)
{
    _value = intValue << _fractionalBits;
}

//float 
Fixed::Fixed(const float floatValue)
{
    _value = roundf(floatValue * (1 << _fractionalBits)); 
}

//copy contructor
Fixed::Fixed(const Fixed& other):_value(other._value)
{
    // this->_value = other.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

//assignment constructor
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
        // this->_value = other.getRawBits();
    return (*this);
}

//destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

////CONVERTOR
float Fixed::toFloat(void) const
{
    return (float) _value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return (int) (_value >> _fractionalBits);
}

//comparison operators: > < >= <= == != 
bool Fixed::operator>(const Fixed& other) const
{
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (_value != other._value);
}

////calculate operator
/**
 * Call the toFloat() method on the current object (this)
 * Convert the current Fixed object to a floating-point number
 * Call toFloat() on the other object (another Fixed number)
 * Convert other to a float
 * Adds the floating-point values of both Fixed numbers
 */
Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed) (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed) (this->toFloat() - other.toFloat()); 
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed) (this->toFloat() * other.toFloat());  
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0)
    {
        std::cerr << "Error: Cannot Devide 0" << std::endl;
        return false;
    }
    return Fixed(this->toFloat() / other.toFloat());
}

/**
 * @note Pre-increment/decrement
 * - modifies the object and returns a reference to it
 * - operation happen before returning => return *this as a reference to the current object.
 * - returning a reference (Fixed&) avoids making a copy, improving performance
 * 
 * @note Post-increment/decrement
 * - returns the original value before modifying the object.
 * - Need to return the previous value => store the current object (temp = *this
*/
//++increment
Fixed& Fixed::operator++()
{
    _value = _value + 1;// Increase the value first
    return (*this);// Return the modified object
}


/** //increment++
 * - Creates a temporary copy of the object
 * - Increase the original object
 * - Returns the tmp (original value before increment/decrement
 */
Fixed Fixed::operator++(int)
{
    Fixed og = *this;
    _value = _value + 1;
    return (og);
}

//--decrement
Fixed& Fixed::operator--()
{
    _value = _value -1;//decrease first
    return (*this);
}

//decrement--
Fixed Fixed::operator--(int)
{
    Fixed og = *this;
    _value = _value - 1;
    return (og);
}

///min & max
//min
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

//max
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

////Output stream overload
//Overloads the << operator to allow std::cout << fixedObject;
std::ostream& operator<<(std::ostream& output, const Fixed& fixedNb) 
{
    output << fixedNb.toFloat();
    return output;
}
