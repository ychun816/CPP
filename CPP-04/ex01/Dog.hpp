#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal  // Correct class inheritance
{
public:
    Dog();  // Default constructor
    Dog(const Dog& other);  // Copy constructor
    Dog& operator=(const Dog& other);  // Assignment operator
    ~Dog();  // Destructor

    void makeSound() const;  // Override base class method
    Brain* getBrain() const;
};

#endif
