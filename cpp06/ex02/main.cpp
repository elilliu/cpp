#include "Base.hpp"

int	main(void)
{
	srand(time(NULL));

	identify(generate());
	identify(*generate());

	return (0);
}
