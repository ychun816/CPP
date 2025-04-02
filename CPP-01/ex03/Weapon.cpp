#include "Weapon.hpp"

//!!assign weaponName to _weaponName
Weapon::Weapon(std::string weaponName) : _weaponName(weaponName) {}
Weapon::~Weapon(){}

void Weapon::setType(std::string weaponType)
{
    _weaponName = weaponType;
    // weaponType = _weaponName;//WRONG~~~~~
}

std::string Weapon::getType() const 
{
    return (_weaponName);
}