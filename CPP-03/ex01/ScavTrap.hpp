#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

//Derived Class(ScavTrap) frm Base Class(ClapTrap)
class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& other);//Copy constructor (creates a new ScavTrap by copying another)
        ScavTrap& operator=(const ScavTrap& other);//Copy assignment operator (copies one ScavTrap to another after creation)
        ScavTrap(std::string name);//constructor with name
        ~ScavTrap();
        
        //member funcs
        void attack(const std::string& target);
        void guardGate();

        //getters
        // std::string getName() const;
        // unsigned int getHitPoints() const;
        // unsigned int getEnergyPoints() const;
        // unsigned int getAttackDamage() const;

};

#endif