#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

/** Rules for HumanA & HumanB:
 * - They both have a Weapon and a name
 * - While HumanA takes the Weapon in its constructor, HumanB does not
 * - HumanB may not always have a weapon, whereas HumanA will always be armed
*/
/** @note Weapon* _weaponB;
 * - Can be null
 * - Can be assigned (=changed to point to something else)
 * - Change to the pointed object affect only this pointer
 */
class HumanB
{
    public:
        HumanB(std::string nameB);
        ~HumanB();

        void setWeapon(Weapon& weaponBType);
        void attack();

    private:
        std::string _nameB;
        Weapon* _weaponB;//may not always have weapon
};

#endif