#include "ClapTrap.hpp"

/*subject rules
When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it regains <amount> hit points.
Attacking and repairing each cost 1 energy point.
ClapTrap can’t do anything if it has no hit points or energy points left.
*/

/** @note static 
 * Inside a class ➝ Use static if the function doesn’t need 'this'
 * Outside a class ➝ Use static if need to limit the function's scope to the current .cpp file
 * -> no need to declare in hpp file!
*/
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
    std::cout << std::endl;

    std::cout << "===== Display Initial Stats =====" << std::endl;
    displayClapTrapInfo(villain);
    displayClapTrapInfo(hero);
    std::cout << std::endl;

    //Villain attack hero
    std::cout << "===== Attack & Damange (5 Rounds) =====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "🗡️ ROUND [" << i + 1 << "]" << std::endl;
        villain.attack(hero.getName());
        hero.takeDamage(villain.getAttackDamage());
        std::cout << std::endl;
    }
    displayClapTrapInfo(villain);
    displayClapTrapInfo(hero);
    std::cout << std::endl<< std::endl;

    //hero repais after attack
    std::cout << "===== Hero Repairs Himself (3 Times) =====" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "🛠️ Repair [" << i + 1 << "]" << std::endl;
        hero.beRepaired(3);
    }
    displayClapTrapInfo(hero);
    std::cout << std::endl << std::endl;

    //hero try to attack
    std::cout << "===== Drain Hero's Energy Completely =====" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "🗡️ Attack [" << i + 1 << "] | ";
        hero.attack("LAZINESS");
    }
    hero.attack("MONSTER"); // attack with no energy
    hero.beRepaired(5);   // repair with no energy
    displayClapTrapInfo(hero);
    std::cout << std::endl << std::endl;

    std::cout << "===== Fatal Damage: Set HP to 0 =====" << std::endl;
    hero.takeDamage(100);
    hero.attack("VALDOR");  // try attacking with 0 HP
    hero.beRepaired(10);    // try repairing with 0 HP
    displayClapTrapInfo(hero);
    std::cout << std::endl << std::endl;

    std::cout << "===== Copy Constructor Test =====" << std::endl;
    ClapTrap clone(hero);
    displayClapTrapInfo(clone);
    std::cout << std::endl << std::endl;

    std::cout << "===== Assignment Operator Test =====" << std::endl;
    ClapTrap another("AnotherOne");
    another = villain;
    displayClapTrapInfo(another);
    std::cout << std::endl << std::endl;

    std::cout << "===== Destructors =====" << std::endl;
    return 0;
}