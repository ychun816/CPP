#include "HumanB.hpp"

//C++98, which does not support nullptr => use "NULL"
HumanB::HumanB(std::string nameB) : _nameB(nameB), _weaponB(NULL)
{
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weaponBType)
{
    // _weaponB(nullptr)
    _weaponB = &weaponBType;
}

void HumanB::attack()
{
    // <name> attacks with their <weapon type>
    //if have weapon
    if (_weaponB)
        std::cout << _nameB << " attacks with " << _weaponB->getType() << std::endl;
    else//if no weapon
        std::cout << _nameB << " attacks with NO WEAPONS! JUST BARE HANDS!!" << std::endl;
}