#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

//Derived concrete class (Inherit frm Base Abstract Class-Animal)
class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound() const;
};

#endif