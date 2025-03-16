#include "HumanA.hpp"


HumanA::HumanA(std::string nameA, Weapon& weaponAName) : _nameA(nameA), _weaponA(weaponAName)//member initializer list
{
}
//OTHER WAY:
// HumanA::HumanA(std::string nameA, Weapon& weaponAName) : _weaponA(weaponAName)//member initializer list
// {
//     _nameA = nameA;//assignment
// }

HumanA::~HumanA()
{

}

// std::string HumanA::getType() const
// {
//     return ();
// }

void HumanA::attack()
{
    // <name> attacks with their <weapon type>
    std::cout << _nameA << " attacks with " <<  _weaponA.getType() << std::endl;
}