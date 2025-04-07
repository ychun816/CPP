#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
// #include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap& other);//copy
        FragTrap& operator=(const FragTrap& other);//assign
        FragTrap(std::string name);//set name
        ~FragTrap();

        //member funcs
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif 