#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;// DiamondTrap's own name
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        DiamondTrap(std::string name);
        ~DiamondTrap();
        
        //member funcs
        void attack(const std::string& target);
        void whoAmI();

};

#endif