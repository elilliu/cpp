#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->_book_size = 0;
}

void	PhoneBook::add()
{
	std::cout << "\033[2J\033[;H";
	std::cout << "ADDING NEW CONTACT\n" << std::endl;

	Contact newcontact(this->_book_size % 8);
	this->_contacts[this->_book_size % 8] = newcontact;
	this->_book_size++;
	std::cout << "New contact added" << std::endl;
	sleep(1);
}

void	PhoneBook::display()
{
	if (!this->_book_size)
	{
		std::cout << "Phonebook is empty.\n" << std::endl;
		return ;
	}

	std::cout << "\033[2J\033[;H";
	std::cout << "CONTACTS\n" << std::endl;

	int	nb = this->_book_size;
	if (nb > 8)
		nb = 8;
	for (int i = 0; i < nb; i++)
		this->_contacts[i].info_summary();
	std::cout << std::endl;

	std::string input;
	do
	{
		std::cout << "Please select a contact\nContact index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	} while (input.empty() || !std::isdigit(input[0]) || input.size() > 1 || std::atoi(input.c_str()) > nb - 1);
	this->_contacts[std::atoi(input.c_str())].info_complete();
}
