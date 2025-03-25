#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

//construtor with name
FragTrap::FragTrap(std::string name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊 (Grandchild Constructor) FragTrap created : " << _name << " 𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊" << std::endl;
}

//copy
FragTrap::FragTrap(const FragTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "FragTrap " << _name << " copied!" << std::endl;
}

//assign
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "FragTrap " << _name << " assigned!" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊 (GrandChild Destructor) FragTrap closed : " << _name << " 𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊" << std::endl;
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
