#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

///Derived concrete class (inherit frm Interface-ICharacter)
class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
    
    public:
        Character();
        Character(std::string type);
        Character(const Character& src);
        Character& operator=(const Character& src);
        ~Character();
    
        ////getter
        std::string const& getName() const;

        ////member funcs
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif