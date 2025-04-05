#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void displayClapTrapInfo(const ClapTrap& clapTrap)
{
    std::cout << "﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌ [STATUS] ﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌" << std::endl;
    std::cout << "Name: " << clapTrap.getName() << std::endl;
    std::cout << "Hit Points: " << clapTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clapTrap.getAttackDamage() << std::endl;
    std::cout << "﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌" << std::endl;
}

int main()
{
    std::cout << "===== Create ClapTraps =====" << std::endl;
    ClapTrap villain("👹VALDOR");
    ClapTrap hero("🧙HARRY");

    std::cout << "\n===== Display Initial Stats =====" << std::endl;
    displayClapTrapInfo(villain);
    displayClapTrapInfo(hero);

    std::cout << "\n===== Attack & Damage (5 Rounds) =====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "🗡️ ROUND [" << i + 1 << "]" << std::endl;
        villain.attack(hero.getName());
        hero.takeDamage(villain.getAttackDamage());
        std::cout << std::endl;
    }

    displayClapTrapInfo(villain);
    displayClapTrapInfo(hero);

    std::cout << "\n===== Hero Repairs Himself (3 Times) =====" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "🩸 TIMES [" << i + 1 << "] | ";
        hero.beRepaired(3);
    }

    std::cout << "\n===== Drain Hero's Energy Completely =====" << std::endl;
    for (int i = 0; i < 50; i++)
    {
        std::cout << "🪄 ROUND [" << i + 1 << "] | ";
        hero.attack("MONSTER");
    }
    hero.attack("MONSTER"); // Should show out of energy

    std::cout << "\n===== Fatal Damage: Set HP to 0 =====" << std::endl;
    villain.takeDamage(100); // Set to 0 HP

    std::cout << "\n\n🌱🪻🌱🥀🌱🌷🌱🌾🌱🌱🌱🌾🌱🪻🌱🌷🌱🌱🌱🌾🌱🪻🌱🌷🌱🌱🌱🌾🌱🪻🌱" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "===== SCAVTRAP TEST =====" << std::endl;
    std::cout << "=========================" << std::endl;

    std::cout << "\n===== Create ScavTrap =====" << std::endl;
    ScavTrap gatekeeper("🛡️ GUARDIAN");

    std::cout << "\n===== Display Initial Stats  =====" << std::endl;
    displayClapTrapInfo(gatekeeper); // Check ScavTrap stats: HP = 100, EP = 50, AD = 20

    std::cout << "\n===== Attack & Damage (5 Rounds) =====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "🗡️ ROUND [" << i + 1 << "] | ";
        gatekeeper.attack("INTRUDER");
        // Assuming the base class method prints damage
    }
    displayClapTrapInfo(gatekeeper);

    std::cout << "\n===== ScavTrap Uses GuardGate =====" << std::endl;
    gatekeeper.guardGate(); // Test ScavTrap's special ability

    std::cout << "\n===== Drain ScavTrap's Energy Completely =====" << std::endl;
    for (int i = 0; i < 50; i++)
    {
        std::cout << "🗡️ ROUND [" << i + 1 << "] | ";
        gatekeeper.attack("MONSTER");
    }
    gatekeeper.attack("MONSTER"); // Should show out of energy for ScavTrap

    std::cout << "\n\n===== Destructors =====" << std::endl;
    // ScavTrap will be destroyed first, then ClapTrap will be destroyed.
    return 0;
}

// int main()
// {
//     ////claptrap
//     std::cout << "===== [CLAPTRAP] =====" << std::endl;
//     ClapTrap clap = ClapTrap("👹CLAP PAPA");
//     //target1
//     clap.attack("target A");
//     clap.takeDamage(5);
//     clap.beRepaired(3);
//     displayClapTrapInfo(clap);

//     //target2
//     clap.attack("target B");
//     clap.takeDamage(15);
//     clap.beRepaired(10);
//     std::cout << std::endl;

//     ////scavtrap
//     // _hitPoints = 100;
//     // _energyPoints = 50;
//     // _attackDamage = 20;
//     std::cout << "===== [SCAVTRAP] =====" << std::endl;
//     ScavTrap scav = ScavTrap("🐣GUARDIAN SCAV");
//     //moster1
//     scav.attack("monster A");
//     scav.takeDamage(20);
//     scav.beRepaired(15);
//     scav.guardGate();
//     //moster2
//     scav.attack("monster B");
//     scav.takeDamage(100);
//     scav.beRepaired(5);
//     scav.guardGate();

//     return 0;
// }

/* test ref
int	main(void)
{
	std::cout << "=== ClapTrap Testing ===" << std::endl;
	ClapTrap clap("Clappy");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.attack("Target2");
	clap.takeDamage(15);
	clap.beRepaired(10);
	std::cout << std::endl;

	// ScavTrap Testing
	std::cout << "=== ScavTrap Testing ===" << std::endl;
	ScavTrap scav("Guardian");

	scav.attack("Bandit");
	scav.takeDamage(20);
	scav.beRepaired(15);
	scav.guardGate();
	scav.attack("Enemy");
	scav.takeDamage(100); // Make health 0
	scav.beRepaired(5);   // Reparing without health

	return (0);
}
*/