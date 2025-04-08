#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
		return ((std::cout << "Please put one level as argument" << std::endl), 1);
	harl.filter(av[1]);
	return (0);
}
