#include "HumanB.hpp"

//C++98, which does not support nullptr => use "NULL"

////CONSTRUCTOR | DESTRUCTOR
HumanB::HumanB(std::string nameB) : _nameB(nameB), _weaponB(NULL){}
HumanB::~HumanB(){}

////MEMBER FUNCS
//set weapon
void HumanB::setWeapon(Weapon& weaponBType)
{
    _weaponB = &weaponBType;
}

//attack
void HumanB::attack()
{
    // <name> attacks with their <weapon type>
    if (_weaponB)
        std::cout << _nameB << " attacks with " << _weaponB->getType() << std::endl;
    else
        std::cout << _nameB << " attacks with NO WEAPONS! JUST BARE HANDS!!" << std::endl;
}