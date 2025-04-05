#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    //// CLAPTRAP TEST
    std::cout << "===== [CLAPTRAP TEST] =====" << std::endl;
    ClapTrap clap("👹PAPA");
    displayClapTrapInfo(clap);
    
    // Test attack on enemy A
    clap.attack("👿enemy A");
    clap.takeDamage(5);  // Take 5 damage, should reduce HP
    clap.beRepaired(3);  // Repair 3 HP, should increase HP
    displayClapTrapInfo(clap);  // Display updated ClapTrap status
    
    // Test attack on enemy B
    std::cout << std::endl;
    clap.attack("👿enemy B");
    clap.takeDamage(15); // Should drop HP to 0
    clap.beRepaired(10); // Should fail, ClapTrap is dead
    displayClapTrapInfo(clap);  // Display updated ClapTrap status

    //// SCAVTRAP TEST
    std::cout << "\n\n🌱🪻🌱🥀🌱🌷🌱🌾🌱🌱🌱🌾🌱🪻🌱🌷🌱🌱🌱🌾🌱🪻🌱🌷🌱🌱🌱🌾🌱🪻🌱" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "===== FRAGTRAP TEST =====" << std::endl;
    std::cout << "=========================" << std::endl;

    // Test ScavTrap creation with name
    ScavTrap scav("🛡️ GUARDIAN");
    displayClapTrapInfo(scav);  // Display initial ScavTrap status
    
    // Test attack on monster A
    scav.attack("👻Monster A");
    scav.takeDamage(50);  // Take 50 damage, should reduce HP
    scav.beRepaired(30);  // Repair 30 HP, should increase HP
    scav.guardGate();     // Test ScavTrap's special "guard gate" ability
    displayClapTrapInfo(scav);  // Display updated ScavTrap status
    
    // Test attack on monster B
    std::cout << std::endl;
    scav.attack("👻Monster B");
    scav.takeDamage(100); // Should drop HP to 0
    scav.beRepaired(20);  // Should fail, ScavTrap is dead
    scav.guardGate();     // Test guard gate after death (shouldn't be possible)
    displayClapTrapInfo(scav);  // Display updated ScavTrap status

    //// FRAGTRAP TEST
    std::cout << "\n\n🌱🪻🌱🥀🌱🌷🌱🌾🌱🌱🌱🌾🌱🪻🌱🌷🌱🌱🌱🌾🌱🪻🌱🌷🌱🌱🌱🌾🌱🪻🌱" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "===== FRAGTRAP TEST =====" << std::endl;
    std::cout << "=========================" << std::endl;

    // Test FragTrap creation with name
    FragTrap frag("💣BOMBER");
    displayClapTrapInfo(frag);
    
    // Test attack on villain A
    frag.attack("👾Villain A");
    frag.takeDamage(40);  // Take 40 damage, should reduce HP
    frag.beRepaired(20);  // Repair 20 HP, should increase HP
    frag.highFivesGuys(); // Test FragTrap's special "high five" ability
    displayClapTrapInfo(frag);  // Display updated FragTrap status

    // Additional test scenario: FragTrap after taking massive damage
    std::cout << "\n===== [ADDITIONAL SCENARIOS] =====" << std::endl;
    frag.takeDamage(90);  // HP should go to 0
    frag.beRepaired(50);  // Trying to repair when dead -> should fail
    frag.attack("👾Villain B"); // Trying to attack without health -> should fail (HP=0)
    displayClapTrapInfo(frag);  // Display updated FragTrap status

    // Check if attack and repair work after FragTrap has no HP
    std::cout << "\n===== [FRAGTRAP DEAD CASES] =====" << std::endl;
    frag.attack("👾Villain C");  // Should fail due to dead status (HP=0)
    frag.takeDamage(10);       // Should not affect HP, FragTrap is already dead
    frag.beRepaired(10);       // Should fail because FragTrap is dead
    displayClapTrapInfo(frag);  // Display final FragTrap status

    return 0;
}

// int main()
// {
//     ////CLAPTRAP
//     std::cout << "===== [CLAPTRAP TEST] =====" << std::endl;
//     ClapTrap clap = ClapTrap("👹CLAP PAPA");
//     //target1
//     clap.attack("👿enemy A");
//     clap.takeDamage(5);
//     clap.beRepaired(3);
//     //target2
//     std::cout << std::endl;
//     clap.attack("👿enemy B");
//     clap.takeDamage(15);// Should drop HP to 0
//     clap.beRepaired(10);// Should **fail** because it's dead

//     ////SCAVTRAP
//     // _hitPoints = 100;
//     // _energyPoints = 50;
//     // _attackDamage = 20;
//     std::cout << "\n===== [SCAVTRAP TEST] =====" << std::endl;
//     ScavTrap scav = ScavTrap("🛡️ GUARDIAN SCAV");
//     //moster1
//     scav.attack("👹 Monster A");
//     scav.takeDamage(50);
//     scav.beRepaired(30);//should work
//     scav.guardGate();// Should print mode activation
//     //moster2
//     std::cout << std::endl;
//     scav.attack("👹 Monster B");
//     scav.takeDamage(100);// Should **die**
//     scav.beRepaired(20);// Should **fail**
//     // scav.guardGate();

//     ////FRAGTRAP
//     //Hit points (100), representing the health of the ClapTrap
//     //Energy points (100)
//     //Attack damage (30)
//     std::cout << "\n===== [FRAGTRAP TEST] =====" << std::endl;
//     FragTrap frag = FragTrap("💣BOMBER FRAG");
//     //villain1
//     frag.attack("Villain A");
//     frag.takeDamage(40);
//     frag.beRepaired(20);//should work
//     frag.highFivesGuys();

// 	//EDGE CASE: Additional FragTrap Scenarios villain B
// 	std::cout << "\n===== [ADDITIONAL SCENARIOS] =====" << std::endl;
// 	frag.takeDamage(90);  // HP should go to 0
// 	frag.beRepaired(50);  // Reparing without health -> should fail
// 	frag.attack("Villain B"); // Attack without health// Should **fail** (HP=0)

//     return 0;
// }
