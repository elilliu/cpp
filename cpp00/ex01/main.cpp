#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	display_help()
{
	std::cout << "\033[2J\033[;H";
	std::cout << "HELP\n" << std::endl;
	std::cout << "ADD: Add a new contact to the phonebook.\nSEARCH: Display contact informations.\nEXIT: Exit phonebook.\n" << std::endl;
}

void	interface(PhoneBook book)
{
	std::string input;

	while (input != "EXIT")
	{
		if (std::cin.eof())
		{
			std::cout << "\033[2J\033[;H";
			break ;
		}
		std::cout << "\033[2J\033[;H";
		std::cout << "Commands:\nADD, SEARCH, EXIT, HELP\n" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
		{
			book.display();
			std::cout << "Press return to go back to the menu." << std::endl;
			std::getline(std::cin, input);
		}
		else if (input == "HELP")
		{
			display_help();
			std::cout << "Press return to go back to the menu." << std::endl;
			std::getline(std::cin, input);
		}
	}
}

int		main()
{
	PhoneBook book;
	interface(book);
	return (0);
}
