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
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ScavTrap(std::string name);
        ~ScavTrap();
        
        //member funcs
        void attack(const std::string& target);
        void guardGate();
};

#endif