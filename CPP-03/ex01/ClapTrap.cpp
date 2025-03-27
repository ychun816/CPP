#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    // std::cout << "------ Default Contructor Created ------" << std::endl << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "------ (Contructor) ClapTrap Created : " << _name << " ------" << std::endl << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << "is copied!" << std::endl;
}

//assignation operator
ClapTrap ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << "is assigned!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << std::endl << "------ (Destructor) ClapTrap Closed : " << _name << " ------" << std::endl;
}

// void ClapTrap::setName(const std::string& name)
// {
//     _name = name;
// }

////Attacking and repairing each cost 1 energy point.
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "💀ClapTrap " << _name << " has no energy to attack!" << std::endl;
}

//Hit points (10), representing the health of the ClapTrap
void ClapTrap::takeDamage(unsigned int amount)
{

    if (amount > _hitPoints) 
        std::cout << "🚫ClapTrap " << _name << " is already destroyed! Can't take damage at all!" << std::endl;
    else 
    {
        _hitPoints = _hitPoints - amount;
        std::cout << "💥ClapTrap " << _name << " takes " << amount << " points of damage! Remaining HP: " << _hitPoints << std::endl;
        if (_hitPoints == 0)
        {
            std::cout << "->> 🆘💀Out of HP! ClapTrap " << _name << " cannot take more damage!🆘" << std::endl;
        }
    }
}

//When ClapTrap repairs itself, it regains <amount> hit points.
//Attacking and repairing each cost 1 energy point.
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints = _hitPoints + amount;
        _energyPoints--;// Deduct 1 energy point
        std::cout << "🩸ClapTrap " << _name << " repairs " << amount << " points! Remaining HP after repair: " << _hitPoints << std::endl;
    }
    else if (_hitPoints <= 0)
        std::cout << "💀ClapTrap " << _name << " is destroyed and cannot be repaired!" << std::endl;
    else
        std::cout << "💀ClapTrap " << _name << " is out of energy and cannot be repaired!" << std::endl;
}