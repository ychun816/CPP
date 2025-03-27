#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();//default construct
        Cat(Cat& other);//copy
        Cat operator=(Cat& other);//assign operator
        ~Cat();//destruc
    

};

#endif