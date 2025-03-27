#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal  // Correct class inheritance
{
public:
    Dog();  // Default constructor
    Dog(const Dog& other);  // Copy constructor
    Dog& operator=(const Dog& other);  // Assignment operator
    ~Dog();  // Destructor

    void makeSound() const;  // Override base class method
};

#endif
// #ifndef DOG_HPP
// #define DOG_HPP

// #include "Animal.hpp"

// //DERIVED CLASS
// class Dog : public Animal
// {
//     public:
//         Dog();//default construct
//         Dog(const Dog& other);//copy
//         Dog& operator=(Dog& other);//assign operator
//         ~Dog();//destruc
    
//         void makeSound(void) const;
// };

// #endif