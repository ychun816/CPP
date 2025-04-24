#include "ABC.hpp"

//A
A::A() : Base() 
{
    std::cout << "A constructor called" << std::endl;
}
A::~A()
{
    std::cout << "A destructor called" << std::endl;
}


//B
B::B() : Base() 
{
    std::cout << "B constructor called" << std::endl;
}
B::~B()
{
    std::cout << "B destructor called" << std::endl;
}


//C
C::C() : Base() 
{
    std::cout << "C constructor called" << std::endl;
}
C::~C()
{
    std::cout << "C destructor called" << std::endl;
}