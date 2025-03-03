// #include "PhoneBook.hpp"
// #include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>

void	interface()
{
	std::string input;

	while (input != "EXIT")
	{
		std::cout << "\033[2J\033[;H";
		std::cout << "Commands:\nADD, SEARCH, EXIT, HELP\n" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
	}
}

int		main()
{
	// PhoneBook book;
	interface();
	return (0);
}
