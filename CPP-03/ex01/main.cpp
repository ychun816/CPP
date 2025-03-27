#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ////claptrap
    std::cout << "===== [CLAPTRAP] =====" << std::endl;
    ClapTrap clap = ClapTrap("👹CLAP PAPA");
    //target1
    clap.attack("target A");
    clap.takeDamage(5);
    clap.beRepaired(3);
    //target2
    clap.attack("target B");
    clap.takeDamage(15);
    clap.beRepaired(10);
    std::cout << std::endl;

    ////scavtrap
    // _hitPoints = 100;
    // _energyPoints = 50;
    // _attackDamage = 20;
    std::cout << "===== [SCAVTRAP] =====" << std::endl;
    ScavTrap scav = ScavTrap("🐣GUARDIAN SCAV");
    //moster1
    scav.attack("monster A");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    //moster2
    scav.attack("monster B");
    scav.takeDamage(100);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}

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