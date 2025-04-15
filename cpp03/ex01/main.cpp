#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	bob("Bob");
	ScavTrap	henri("Henri");

	std::cout << '\n';
	henri.attack("Bob");
	bob.takeDamage(20);
	bob.attack("Henri");
	std::cout << '\n';

	ScavTrap	henriv2(henri);
	std::cout << '\n';

	henri.beRepaired(3);
	henriv2.attack("Henri");
	henri.takeDamage(20);
	henri.beRepaired(3);
	henri.attack("Henri_v2");
	henriv2.takeDamage(20);
	std::cout << '\n';

	henri.guardGate();
	henriv2.guardGate();
	std::cout << '\n';
}
