#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
    private:


    public:
        ScavTrap();
        ScavTrap(std::string name);//constructor with name
        ScavTrap(const ScavTrap& other);//Copy constructor (creates a new ScavTrap by copying another).
        ScavTrap& operator=(const ScavTrap& other);//Copy assignment operator (copies one ScavTrap to another after creation).
        ~ScavTrap();
        
        void guardGate();

};
// class ClapTrap
// {
//     private:
//         std::string _name;
//         unsigned int _hitPoints;
//         unsigned int _energyPoints;
//         unsigned int _attackDamage;

//     public:
//         ClapTrap();
//         ClapTrap(const std::string& name);
//         ~ClapTrap();
        
//         // void setName(const std::string& name);
        
//         void attack(const std::string& target);
//         void takeDamage(unsigned int amount);
//         void beRepaired(unsigned int amount);
// };

#endif