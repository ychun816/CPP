#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

//They both have a Weapon and a name.
//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed.
class HumanB
{
    public:
        HumanB(std::string nameB);
        ~HumanB();

        void setWeapon(Weapon& weaponBType);
        void attack();

    private:
        std::string _nameB;
        Weapon* _weaponB;//may have a weapon or not 
};

#endif