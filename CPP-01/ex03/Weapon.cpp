#include "Weapon.hpp"

//!!assign weaponName to _weaponName
// Weapon::Weapon(std::string weaponName) : _weaponName(weaponName) {}

Weapon::Weapon(std::string weaponName)
{
    _weaponName = weaponName;//assign, initialized
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string weaponType)
{
    _weaponName = weaponType; // Correctly updates the weapon name
    // weaponType = _weaponName;//WRONG~~~~~

}

std::string Weapon::getType() const 
{
    return (_weaponName);
}

//FOR FIRST TEST:
// void Weapon::attack()
// {
//     std::cout << " attacks with " << getType() << std::endl;
// }