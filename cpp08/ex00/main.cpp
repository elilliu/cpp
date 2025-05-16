#include "easyfind.hpp"

int	main() {
	int	myints[] = {10, 20, 30, 40, 50};
	std::vector<int>	myvector(myints, myints + 5);

	std::cout << "My vector: ";
	for (int i = 0; i < 5; i++) {
		std::cout << myvector[i];
		if (i != 4)
			std::cout << ", ";
	}
	std::cout << std::endl;

	try
	{
		easyfind(myvector, 30);
		easyfind(myvector, 35);
		easyfind(myvector, 40);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
