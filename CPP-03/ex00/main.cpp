#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap = ClapTrap("👹THE GIANTS");

    clapTrap.attack("🧌 VILLANGER 1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(4);//hitpoint = 9

    std::cout << std::endl;
    clapTrap.attack("🧞 VILLANGER 2");
    clapTrap.takeDamage(8);
    clapTrap.beRepaired(5);

    return 0;
}