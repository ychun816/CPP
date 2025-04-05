#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

/**
 * virtual in ClapTrap 
 * → Allows derived classes to override attack() and ensures dynamic function calls at runtime.
 * virtual 關鍵字的作用是啟用多型（polymorphism），讓子類別（ScavTrap）可以覆蓋（override）父類別（ClapTrap）
 */
class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);//copy 
        ClapTrap& operator=(const ClapTrap& other);//assign
        ClapTrap(const std::string& name);//set name
        ~ClapTrap();
        
        //member funcs
        virtual void attack(const std::string& target);//change to virtual
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //getters
        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;
};

#endif 