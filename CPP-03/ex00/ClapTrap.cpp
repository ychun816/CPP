#include "ClapTrap.hpp"

//CONSTRUCTORS & DESTRUCTORS
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "--- Default Constructor Created ---" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "--- (Contructor) ClapTrap Created : " << _name << " ---" << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << " Copied" << std::endl;
}

//assignation operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " Assigned" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "--- (Destructor) ClapTrap Destroyed : " << _name << " ---" << std::endl;
}

//GETTERS
std::string ClapTrap::getName() const { return (_name);}
unsigned int ClapTrap::getHitPoints() const {return (_hitPoints);}
unsigned int ClapTrap::getEnergyPoints() const {return (_energyPoints);}
unsigned int ClapTrap::getAttackDamage() const {return (_attackDamage);}

//MEMBER FUNCS
//attack
//Attacking and repairing each cost 1 energy point
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_hitPoints == 0)
        std::cout << "🚫ClapTrap " << _name << " is destroyed and cannot attack!" << std::endl;
    else
        std::cout << "💀ClapTrap " << _name << " has no energy to attack!" << std::endl;

}

//takeDamage
//Hit points (10), representing the health of the ClapTrap
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "🚫 ClapTrap " << _name << " is already destroyed! Can't take more damage!" << std::endl;
        return;
    }

    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "💥ClapTrap " << _name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "💥ClapTrap " << _name << " takes " << amount << " points of damage! Remaining HP: " << _hitPoints << std::endl;
    }
}

//beRepaired
//When ClapTrap repairs itself, it regains <amount> hit points.
//Attacking and repairing each cost 1 energy point.
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints = _hitPoints + amount;
        _energyPoints--;// Deduct 1 energy point
        std::cout << "🩸ClapTrap " << _name << " repairs " << amount << " points! Remaining HP after repair: " << _hitPoints << std::endl << std::endl;
    }
    else if (_hitPoints <= 0)
        std::cout << "💀ClapTrap " << _name << " is destroyed and cannot be repaired!"<< std::endl << std::endl;
    else
        std::cout << "💀ClapTrap " << _name << " is out of energy and cannot be repaired!" << std::endl << std::endl;
}

/* ALTERNATIVE
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
            std::cout << "->> 🆘💀Out of HP! ClapTrap " << _name << " cannot take more damage!" << std::endl;
        }
    }
}
*/