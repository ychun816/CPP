#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap = ClapTrap("THE GIANTS👹");
    // clapTrap.setDamage(5);
    clapTrap.attack("VILLANGE 1🏘");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(8);

    clapTrap.attack("VILLANGE 2🏘");
    clapTrap.takeDamage(9);
    clapTrap.beRepaired(6);

    return 0;
}