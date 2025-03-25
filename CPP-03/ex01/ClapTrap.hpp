#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);//set name
        ClapTrap(const ClapTrap& other);//copy constructor
        ClapTrap operator=(const ClapTrap& other);//assignation operator
        ~ClapTrap();
        
        // void setName(const std::string& name);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif 