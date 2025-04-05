#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

//copy
//no need to assign every variable again!!
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "(Child Constructor) FragTrap " << _name << " copied" << std::endl;
}

//assign
//Use ClapTrap's assignment operator
//no need to assign every variable again!!
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _attackDamage = other._attackDamage;
    }
    std::cout << "(Child Constructor) FragTrap " << _name << " assigned" << std::endl;
    return (*this);
}


//construtor with name
FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "(Child Constructor) FragTrap Created : " << _name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "(Child Constructor) FragTrap Destroyed : " << _name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "FragTrap " << _name << " attacks with BOMB! " << target << " encounter " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "🤡FragTrap " << _name << " has no energy to attack!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "👏FragTrap " << _name << " says HIGH FIVE GUYS!!!!" << std::endl;
}
