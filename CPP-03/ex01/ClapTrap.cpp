#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "--- Contructor Called ---" << std::endl << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << std::endl << "--- Destructor Called ---" << std::endl;
}

void ClapTrap::setName(const std::string& name)
{
    _name = name;
}

void ClapTrap::attack(const std::string& target)
{
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    // _attackDamage += 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
}

//Hit points (10), representing the health of the ClapTrap
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_energyPoints != 0)
    {
        _energyPoints = _energyPoints - amount;
        std::cout << "💥ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "💀ClapTrap " << _name << " is out of blood!" << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{
    _energyPoints = _energyPoints + amount;
    std::cout << "🩸ClapTrap " << _name << " repairs " << amount << " points!" << std::endl;
}