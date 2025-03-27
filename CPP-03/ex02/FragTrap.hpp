#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
// #include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);//copy
        FragTrap& operator=(const FragTrap& other);//assign
        ~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif 