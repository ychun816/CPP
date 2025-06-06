#include "ScavTrap.hpp"

//constructs & destructors
ScavTrap::ScavTrap() : ClapTrap()  // Call to base class default constructor
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

//copy
//no need to assign every same variable again!!
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "------ Child Constructor) ScavTrap " << _name << " Copied ------" << std::endl;
}

//assign
// Use ClapTrap's assignment operator
//no need to assign every same variable again!!
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _attackDamage = other._attackDamage;
    }
    std::cout << "------ (Child Constructor) ScavTrap " << _name << " Assigned ------" << std::endl;
    return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // Call to base class constructor with name
{
    _name = name; //Although _name is inherited, still explicitly assign it.
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "------ (Child Constructor) ScavTrap Created : " << _name << " ------" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "------ (Child Destructor) ScavTrap Destroyed : " << _name << " ------" << std::endl;
}

//member funcs
void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks harder!" << target << " received " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "🤡ScavTrap " << _name << " has no energy to attack!" << std::endl;
}



void ScavTrap::guardGate()
{
    std::cout << "🧿ScavTrap " << _name << " is now in Gate keeper mode🧿" << std::endl;
}

