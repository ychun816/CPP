#include "ScavTrap.hpp"

//For inheritance, the derived class (ScavTrap) inherits the members of the base class (ClapTrap)
//calling the base class constructor is generally considered a better practice according to common C++ conventions

//constructs & destructors
ScavTrap::ScavTrap() : ClapTrap()  // Call to base class default constructor
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

//copy
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    ClapTrap::operator=(other); // Use ClapTrap's assignment operator
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << "is copied!" << std::endl;
}

//assign
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // Use ClapTrap's assignment operator
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap " << _name << "is assigned!" << std::endl;
    return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // Call to base class constructor with name
{
    _name = name; //Although _name is inherited, still explicitly assign it.
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "------ (Child Constructor) ScavTrap created : " << _name << " ------" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "------ (Child Destructor) ScavTrap closed : " << _name << " ------" << std::endl;
}

//member funcs
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

