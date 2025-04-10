#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

//possesses an inventory of 4 slots, most 4 Materias
//Deep copy in copy constructor and assignment operator
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
    
        //member funcs
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);


};

#endif