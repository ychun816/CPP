#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== Create DiamondTrap =====" << std::endl;
    DiamondTrap diamond("💎SHINY");

    std::cout << "\n===== TEST attack() =====\n" << std::endl;
    diamond.attack("🧌 GIANT");

    std::cout << "\n===== TEST whoAmI() =====\n" << std::endl;
    diamond.whoAmI();

    std::cout << "\n===== TEST highFiveGuys() (frm FragTrap) =====\n" << std::endl;
    diamond.highFivesGuys();

    std::cout << "\n===== TEST guardGate() (frm FragTrap) =====\n" << std::endl;
    diamond.guardGate();
    std::cout << std::endl;

    return 0;
}