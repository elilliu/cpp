#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie = newZombie("Michel");
	randomChump("Micheline");
	delete (zombie);
}
