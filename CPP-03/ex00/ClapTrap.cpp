#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::setName(const std::string& name)
{
    _name = name;
}

void ClapTrap::attack(const std::string& target)
{
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    std::cout << "ClapTrap " << _name << "attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

//Hit points (10), representing the health of the ClapTrap
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_energyPoints != 0)
    {
        _energyPoints = _energyPoints - amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " is out of blood!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{

}