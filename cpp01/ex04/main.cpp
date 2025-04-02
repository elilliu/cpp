#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::string		newFileName;
	std::string		buff;

	if (ac != 4)
		return (std::cout << "Wrong number of arguments\n", 1);

	newFileName = av[1];
	newFileName.append(".replace");
	std::cout << "New file: " << newFileName << '\n';

	std::fstream	oldFile(av[1], std::fstream::in);
	std::fstream	newFile(newFileName.c_str(), std::fstream::out | std::fstream::trunc);

	return (0);
}
