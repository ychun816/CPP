#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

//They both have a Weapon and a name.
//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed.

class HumanA
{
    public:
        HumanA(std::string nameA, Weapon& weaponAName);
        ~HumanA();

        std::string getType() const;
        void attack();

    private:
        std::string _nameA;
        Weapon& _weaponA;//always have weapon
};

#endif