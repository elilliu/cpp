#include <iostream>

void	megaphone(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		std::cout << (char)std::toupper(str[i]);
}

int	all_empty(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		if (str.find_first_not_of(" \t\v\n") != std::string::npos)
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac < 2 || all_empty(ac, av))
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
		megaphone(av[i]);
	std::cout << std::endl;
	return (0);
}
