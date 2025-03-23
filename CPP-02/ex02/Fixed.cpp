#include "Fixed.hpp"

////CONSTRUCTORS
Fixed::Fixed():_value(0)
{}

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
/*
Why Use value(other.value) Instead of value = other.value;?
Efficiency:
Using the initializer list (value(other.value)) directly initializes value when memory is allocated.
If we use assignment (value = other.value; inside the constructor body), value is first default-initialized and then assigned, which is less efficient.
*/
Fixed::Fixed(const Fixed& other):_value(other._value)
{
}

//assignment constructor
Fixed Fixed::&operator=(const Fixed& other)
{
    if (this != other)
        this = other._value;
    return (*this);
}

//destructor
Fixed::~Fixed()
{}

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

////cal operator
//Calls the toFloat() method on the current object (this)
//Converts the current Fixed object to a floating-point number.
//Calls toFloat() on the other object (another Fixed number).
//Converts other to a float.
//Adds the floating-point values of both Fixed numbers.
Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed) this->toFloat() + other.toFloat();
}
Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed) this->toFloat() - other.toFloat(); 
}
Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed) this->toFloat() * other.toFloat();  
}
Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0)
    {
        std::cerr << "Error: Cannot Devide 0" << std::endl;
        return (false);//1?
    }
    return (Fixed) this->toFloat() / other.toFloat(); 
}

/**
@notes Pre-increment/decrement
- modifies the object and returns a reference to it
- operation happen before returning => return *this as a reference to the current object.
- returning a reference (Fixed&) avoids making a copy, improving performance

@notes Post-increment/decrement
- returns the original value before modifying the object.
- Need to return the previous value => store the current object (temp = *this
*/
//++increment
Fixed& Fixed::operator++()
{
    _value = _value + 1;// Increase the value first
    return (*this);// Return the modified object
}

//increment++
//Creates a temporary copy of the object
//Increase the original object
//Returns the tmp (original value before increment/decrement)
Fixed Fixed::operator++()
{
    Fixed og = *this;
    _value = _value + 1;
    return (og);
}

////--decrement
Fixed& Fixed::operator--()
{
    _value = _value -1;//decrease first
    return (*this);
}

////decrement--
Fixed Fixed::operator--()
{
    Fixed og = *this;
    _value = _value - 1;
    return (og);
}

///min & max

//min
static Fixed& min(Fixed& a, Fixed& b)
{

}

static const Fixed& min(const Fixed& a, const Fixed& b)
{

}

//max
static Fixed& max(Fixed& a, Fixed& b)
{

}

static const Fixed& max(const Fixed& a, const Fixed& b)
{

}

////Output stream overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{

}
