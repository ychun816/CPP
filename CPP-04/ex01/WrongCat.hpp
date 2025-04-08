#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();//default construct
        WrongCat(const WrongCat& other);//copy
        WrongCat& operator=(const WrongCat& other);//assign operator
        ~WrongCat();//destruc
    
        void makeSound(void) const;
};

#endif