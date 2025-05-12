#include "iter.hpp"

int	main(void)
{
	std::string	tab[] = {"red", "orange", "yellow", "green", "blue", "indigo", "purple"};
	int	tab2[] = {1, 2, 3, 4, 5};

	iter(tab, 7, print);
	std::cout << '\n';
	iter(tab2, 5, print);
}
