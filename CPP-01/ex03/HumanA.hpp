#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>

//They both have a Weapon and a name.
//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed.

class HumanA
{
    public:
    HumanA(Weapon& weapon);
    ~HumanA();
    
    attack();

    private:
        std::string& _weaponA;//always have weapon
        std::string _nameA;
}

#endif