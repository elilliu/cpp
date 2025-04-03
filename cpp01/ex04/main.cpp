#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::string		newFileName;
	std::string		buff;
	size_t			i;

	if (ac != 4)
		return (std::cout << "Wrong number of arguments\n", 1);

	std::fstream	oldFile(av[1], std::fstream::in);

	if (oldFile.good())
		std::getline(oldFile, buff, '\0');
	else
		return (std::cout << "Unvalid infile\n", 1);

	oldFile.close();

	std::string oldContent = av[2];

	if (oldContent.empty())
		return (std::cout << "Please provide a content to replace.\n", 1);

	for (i = buff.find(oldContent, 0); i != std::string::npos; i = buff.find(oldContent, i))
	{
		buff.erase(i, oldContent.size());
		buff.insert(i, av[3]);
	}

	newFileName = av[1];
	newFileName.append(".replace");

	std::fstream	newFile(newFileName.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
	if (newFile.is_open())
		newFile << buff;
	else
		return (std::cout << "There was an error creating the new file.\n", 1);

	newFile.close();

	std::cout << "The new file has been succesfully created.\n";

	return (0);
}
