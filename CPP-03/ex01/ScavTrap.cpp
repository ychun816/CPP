#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    // std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "(Child Constructor) ScavTrap " << _name << " is activated" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "(Child Destructor) ScavTrap " << _name << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}