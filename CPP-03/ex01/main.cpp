#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ////claptrap
    std::cout << "[ClapTrap]" << std::endl;
    ClapTrap clapTrap = ClapTrap("👹THE GIANTS");
    //target1
    clapTrap.attack("target1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    //target2
    clapTrap.attack("target2");
    clapTrap.takeDamage(15);
    clapTrap.beRepaired(10);
    std::cout << std::endl;

    ////scavtrap
    // _hitPoints = 100;
    // _energyPoints = 50;
    // _attackDamage = 20;
    std::cout << "[ScavTrap]" << std::endl;
    ScavTrap scavTrap = ScavTrap("🐣BABY SCAV");
    //moster1
    scavTrap.attack("monster1");
    scavTrap.takeDamage(20);
    scavTrap.beRepaired(15);
    scavTrap.guardGate();
    //moster2
    scavTrap.attack("monster2");
    scavTrap.takeDamage(100);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();

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