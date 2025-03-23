#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "--- Default Contructor Created ---" << std::endl << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "--- (Contructor) ClapTrap Created : " << _name << " ---" << std::endl << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << std::endl << "--- (Destructor) ClapTrap Closed : " << _name << " ---" << std::endl;
}

// void ClapTrap::setName(const std::string& name)
// {
//     _name = name;
// }

void ClapTrap::attack(const std::string& target)
{
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "💀ClapTrap " << _name << " is out of energy! DEAD!!" << std::endl;
}

//Hit points (10), representing the health of the ClapTrap
void ClapTrap::takeDamage(unsigned int amount)
{

    if (amount > _hitPoints) 
    {
        // _hitPoints = 0;
        std::cout << "🤡ClapTrap " << _name << " is already destroyed! Can't take damage at all!" << std::endl;
    } 
    else 
    {
        _hitPoints = _hitPoints - amount;
        std::cout << "💥ClapTrap " << _name << " takes " << amount << " points of damage! Remaining HP: " << _hitPoints << std::endl;
        if (_hitPoints == 0)
        {
            std::cout << "->> Out of HP💀! ClapTrap " << _name << " cannot take more damage!" << std::endl;
        }
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints = _hitPoints + amount;
        _energyPoints--;// Deduct 1 energy point
        std::cout << "🩸ClapTrap " << _name << " repairs " << amount << " points!" << std::endl;
    }
    else if (_hitPoints <= 0)
        std::cout << "💀 ClapTrap " << _name << " is destroyed and cannot be repaired!" << std::endl;
    else
        std::cout << "💀ClapTrap " << _name << " is out of energy and cannot be repaired!" << std::endl;
}