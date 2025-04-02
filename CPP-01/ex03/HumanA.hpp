#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

/** Rules for HumanA & HumanB:
 * - They both have a Weapon and a name
 * - While HumanA takes the Weapon in its constructor, HumanB does not
 * - HumanB may not always have a weapon, whereas HumanA will always be armed
*/
/** @note Weapon& _weaponA; > is address > always have value!(=weapon)
 * - Must be initialized at declaration and cannot be null
 * - Changes to the referenced object affect all references to it
 */
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