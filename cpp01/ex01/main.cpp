#include "Zombie.hpp"

int	main(void)
{
	int	N = 6;
	std::string	name = "Patrick";

	Zombie *horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
}
