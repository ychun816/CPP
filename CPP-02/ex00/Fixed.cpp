#include "Fixed.hpp"

//CONSTRUCTORS & DESTRUCTOR
//default
Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/** Copy Constructor
 * @note "this"
 * - a pointer to the current object
 * - *this ->means dereferencing the pointer to access the actual object
 * @note *this = other; 
 * -> call the copy assignment operator (operator=) instead of directly copying the value
 */
Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}
//OTHER WAY 
//Fixed::Fixed(const Fixed& other)
// {
//     std::cout << "Copy constructor called" << std::endl;
//     *this = other;
//     // this->_value = other.getRawBits(); // Copy the value properly
// }

/** Assignment operator overload
 * @note if (this != &other)
 * -> check self-assignment (ie. a = a , unessary)
 * @note const Fixed& other
 * Fixed& → Returns a reference to the current object after assignment.
 * → Takes a constant reference to another Fixed object
 */
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
    return (*this);//allow chaining assignments
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//MEMBER FUNCS
//get raw int value
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

//set raw int value
void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

