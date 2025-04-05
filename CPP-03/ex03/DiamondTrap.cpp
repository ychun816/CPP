#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{

}

//copy
//no need to assign every variable again!!
DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    std::cout << "(Child Constructor) DiamondTrap " << _name << " copied" << std::endl;
}

//assign
//Use ClapTrap's assignment operator
//no need to assign every variable again!!
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {

    }
    std::cout << "(Child Constructor) DiamondTrap " << _name << " assigned" << std::endl;
    return (*this);
}


//construtor with name
DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap(), _name(name) //Initialize FragTrap and ScavTrap (handles inheritance)
{
    ClapTrap::_name = _name + "_clap_name";  // Modify ClapTrap's name to have the "_clap_name" suffix
    _hitPoints = FragTrap::_hitPoints;  // Initialize from FragTrap
    _energyPoints = ScavTrap::_energyPoints;  // Initialize from ScavTrap
    _attackDamage = FragTrap::_attackDamage;  // Initialize from FragTrap
    std::cout << "(Child Constructor) DiamondTrap Created : " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "(Child Constructor) DiamondTrap Destroyed : " << _name << std::endl;
}

//member funcs
void attack(const std::string& target)
{

}

void whoAmI()
{

}