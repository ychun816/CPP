#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "=== (Child Constructor) ScavTrap created : " << _name << " ===" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "=== (Child Destructor) ScavTrap closed : " << _name << " ===" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "🤡ScavTrap " << _name << " is out of energy! DEAD!!" << std::endl;
}



void ScavTrap::guardGate()
{
    std::cout << "🧿ScavTrap " << _name << " is now in Gate keeper mode🧿" << std::endl;
}

