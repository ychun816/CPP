#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName)
{
    // std::getline(std::cin, weaponName);
    weaponName = _weaponName;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string weaponType)
{
    // std::getline(std::cin, weaponType);
    weaponType = _weaponName;
}

void Weapon::attack()
{
    std::cout << " attacks with " << _weaponName << std::endl;
}