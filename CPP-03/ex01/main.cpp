#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    //claptrap
    std::cout << "[CalpTrap]" << std::endl;
    ClapTrap clapTrap = ClapTrap("THE GIANTS👹");
    clapTrap.attack("target1");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(8);
    clapTrap.attack("target2");
    clapTrap.takeDamage(15);
    clapTrap.beRepaired(10);
    std::cout << std::endl;

    //scavtrap
    std::cout << "[ScavTrap]" << std::endl;
    ScavTrap scavTrap = ScavTrap("Baby Scav");
    scavTrap.attack("monster1");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(8);
    scavTrap.guardGate();
    //target2
    scavTrap.attack("monster2");
    scavTrap.takeDamage(100);
    scavTrap.beRepaired(5);
    // scavTrap.guardGate();

    return 0;
}