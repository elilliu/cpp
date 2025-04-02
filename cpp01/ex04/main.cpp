#include "mySed.hpp"

int	main(int ac, char **av)
{
	std::string		newFileName;
	std::fstream	oldFile;

	if (ac != 4)
		return (std::cout << "Wrong number of arguments\n", 1);

	newFileName = av[1];
	newFileName.append(".replace");
	std::cout << "New file: " << newFileName << '\n';

	

	return (0);
}
