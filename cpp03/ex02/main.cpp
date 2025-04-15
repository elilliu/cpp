#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	bob("Bob");
	ScavTrap	henri("Henri");
	FragTrap	ralph("Ralph");
	std::cout << '\n';

	bob.attack("Henri");
	henri.takeDamage(0);
	henri.attack("Ralph");
	ralph.takeDamage(20);
	ralph.beRepaired(5);
	ralph.attack("Henri");
	henri.takeDamage(30);
	henri.beRepaired(10);
	std::cout << '\n';

	henri.guardGate();
	std::cout << '\n';

	ralph.highFivesGuys();
	std::cout << '\n';

	// henri.highFivesGuys();

	FragTrap	anonymous;
	std::cout << '\n';
}
