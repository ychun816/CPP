#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>

//They both have a Weapon and a name.
//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed.
class HumanB
{
    public:
    HumanB(Weapon* weapon);
    ~HumanB();

    setWeapon(Weapon *weapon_type);
    attack();

    private:
        std::string* _weaponB;//may have a weapon or not 
        std::string _nameB;
}

#endif