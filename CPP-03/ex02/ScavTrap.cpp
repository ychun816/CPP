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
    std::cout << "𓆝 𓆟 𓆞 𓆝 (Child Constructor) ScavTrap created : " << _name << " 𓆝 𓆟 𓆞 𓆝" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << "is copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap " << _name << "is assigned!" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "𓆝 𓆟 𓆞 𓆝  (Child Destructor) ScavTrap closed : " << _name << " 𓆝 𓆟 𓆞 𓆝" << std::endl;
}


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

