#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	bob("Bob");

	std::cout << '\n';
	bob.attack("Michel");
	bob.takeDamage(5);
	std::cout << '\n';

	ClapTrap	bobv2(bob);
	std::cout << '\n';

	bob.beRepaired(3);
	bob.takeDamage(8);
	bob.beRepaired(3);
	bob.attack("Michel");
	std::cout << '\n';

	for (int i = 0; i < 10; i++)
		bobv2.attack("Punching ball");
	std::cout << '\n';
}
