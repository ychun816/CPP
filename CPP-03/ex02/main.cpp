#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ////CLAPTRAP
    std::cout << "===== [CLAPTRAP TEST] =====" << std::endl;
    ClapTrap clap = ClapTrap("👹CLAP PAPA");
    //target1
    clap.attack("👿enemy A");
    clap.takeDamage(5);
    clap.beRepaired(3);
    //target2
    std::cout << std::endl;
    clap.attack("👿enemy B");
    clap.takeDamage(15);// Should drop HP to 0
    clap.beRepaired(10);// Should **fail** because it's dead

    ////SCAVTRAP
    // _hitPoints = 100;
    // _energyPoints = 50;
    // _attackDamage = 20;
    std::cout << "\n===== [SCAVTRAP TEST] =====" << std::endl;
    ScavTrap scav = ScavTrap("🛡️ GUARDIAN SCAV");
    //moster1
    scav.attack("👹 Monster A");
    scav.takeDamage(50);
    scav.beRepaired(30);//should work
    scav.guardGate();// Should print mode activation
    //moster2
    std::cout << std::endl;
    scav.attack("👹 Monster B");
    scav.takeDamage(100);// Should **die**
    scav.beRepaired(20);// Should **fail**
    // scav.guardGate();

    ////FRAGTRAP
    //Hit points (100), representing the health of the ClapTrap
    //Energy points (100)
    //Attack damage (30)
    std::cout << "\n===== [FRAGTRAP TEST] =====" << std::endl;
    FragTrap frag = FragTrap("💣BOMBER FRAG");
    //villain1
    frag.attack("Villain A");
    frag.takeDamage(40);
    frag.beRepaired(20);//should work
    frag.highFivesGuys();

	//EDGE CASE: Additional FragTrap Scenarios villain B
	std::cout << "\n===== [ADDITIONAL SCENARIOS] =====" << std::endl;
	frag.takeDamage(90);  // HP should go to 0
	frag.beRepaired(50);  // Reparing without health -> should fail
	frag.attack("Villain B"); // Attack without health// Should **fail** (HP=0)

    return 0;
}

/*


*/