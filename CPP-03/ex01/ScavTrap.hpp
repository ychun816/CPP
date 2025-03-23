#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

class ScavTraip
{
    private:


    public:
        ScavTraip();
        ~ScavTraip();
        
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