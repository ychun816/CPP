#include "Fixed.hpp"

// private:
// int _value;//An integer to store the fixed-point number value
// static const int fractionalBits = 8;//A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8

//A default constructor 
Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//A copy constructor
//use & -> reference to a Fixed object-> 1.avoid copying the object / 2.modify the actual object
//const -> 1. prevent modifying the original object / 2. Ensures that other is only readable
//"this" 
//is a pointer to the current object
//*this ->means dereferencing the pointer to access the actual object
//*this = other; calls the copy assignment operator (operator=) instead of directly copying the value.

//The problem is that the copy assignment operator assumes that *this is already fully constructed, but in a constructor, the object is still being initialized.
// Problem: Object Isn't Fully Constructed Yet
//     When the copy constructor runs, *this is in the middle of being created.
//     The assignment operator (operator=) is meant for assigning an already constructed object.
//     Using *this = other; in a constructor creates unnecessary recursion and may lead to undefined behavior.

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    // *this = other;
    this->_value = other.getRawBits(); // Copy the value properly
}

//A copy assignment operator overload
//Fixed& → Returns a reference to the current object after assignment.
//operator= → This function overloads the = operator.
//(const Fixed& other) → Takes a constant reference to another Fixed object
//Returning *this allows chaining assignments
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    //check self-assignment (ie. a = a , unessary)
    if (this != &other)
        this->_value = this->getRawBits();
    return (*this);
}

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

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
