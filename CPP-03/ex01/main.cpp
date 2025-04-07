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
    //// CLAPTRAP TEST
    std::cout << "=========================" << std::endl;
    std::cout << "===== CLAPTRAP TEST =====" << std::endl;
    std::cout << "=========================" << std::endl;
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
    std::cout << "===== SCAVTRAP TEST =====" << std::endl;
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

    return 0;
}