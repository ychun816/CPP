#include "HumanA.hpp"

////CONSTRUCTOR | DESTRUCTOR
HumanA::HumanA(std::string nameA, Weapon& weaponAName) : _nameA(nameA), _weaponA(weaponAName){}
HumanA::~HumanA(){}

void HumanA::attack()
{
    // <name> attacks with their <weapon type>
    std::cout << _nameA << " attacks with " <<  _weaponA.getType() << std::endl;
}