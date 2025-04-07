#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);//constructor with name
        ScavTrap(const ScavTrap& other);//Copy constructor (creates a new ScavTrap by copying another).
        ScavTrap& operator=(const ScavTrap& other);//Copy assignment operator (copies one ScavTrap to another after creation).
        ~ScavTrap();
        
        void attack(const std::string& target);
        void guardGate();

};

#endif