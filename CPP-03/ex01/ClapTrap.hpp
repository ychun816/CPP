#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
class ClapTrap
{
    protected://private:
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

        virtual void attack(const std::string& target);//change to virtual
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

/**
 * virtual in ClapTrap 
 * → Allows derived classes to override attack() and ensures dynamic function calls at runtime.
 * virtual 關鍵字的作用是啟用多型（polymorphism），讓子類別（ScavTrap）可以覆蓋（override）父類別（ClapTrap）
 */


#endif 