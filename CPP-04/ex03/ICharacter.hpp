#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
#pragma once

#include <iostream>
// #include "AMateria.hpp"

class AMateria;//Forward declare AMateria


class ICharacter 
{
    public:
        virtual ~ICharacter() {}

        ////getter
        virtual std::string const & getName() const = 0;
        
        ////member funcs
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif