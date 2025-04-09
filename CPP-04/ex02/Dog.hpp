#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *_brain;

    public:
        Dog(); 
        Dog(std::string type);//construct with type
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        //member funcs
        void makeSound() const;
        void tellIdea(void) const;

        //getter
        Brain* getBrain() const;
};

#endif
