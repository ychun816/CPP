#include "Dog.hpp"

////constructor &desturctor
Dog::Dog() : Animal("🐕"), _brain(new Brain())
{
    std::cout << "Default Dog " << _type << " is created" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _brain(new Brain())
{
    std::cout << "Dog " << _type << " is created" << std::endl;
}

//copy
//Avoid calling assignment operator from constructor.
//deep copy _brain directly in the initializer list or constructor body
Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Dog " << _type << " has been copied" << std::endl;
}

//assign
//free the current _brain before assigning a new one-> if without -> leak
//Best Practice Rule: Always handle deep-copy and resource management EXPLICITLY for pointer members
//Always use this->_brain in class methods when accessing or assigning member variables. It’s safe, clear, and professional.
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);//Copy base class
        delete _brain;//Clean up existing brain
        this->_brain = new Brain(*other._brain);//Deep copy of new brain
    }
    std::cout << "Dog " << _type << " has been assigned" << std::endl;
    return (*this);
}

//DESTURCTOR
//allocated memory with new Brain(...) in constructor
//free the memory(_brain) in the destructor!!
Dog::~Dog()
{
    std::cout << "Dog " << _type << " is destroyed" << std::endl;
    delete _brain;
}


////getter
Brain* Dog::getBrain() const {return (_brain);}


////member funcs
void Dog::makeSound(void) const
{
    std::cout << "Dog " << _type << " makes sound: Woof! Woof!!" << std::endl;
}

void Dog::tellIdea(void) const
{
	std::cout << this->_brain->getIdea(42) << std::endl;

}