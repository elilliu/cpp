#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->_book_size = 0;
}

void	PhoneBook::add()
{
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
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	int	nb = this->_book_size;
	if (nb > 8)
		nb = 8;
	for (int i = 0; i < nb; i++)
		this->_contacts[i].info_summary();
	std::cout << std::endl;

	std::string input;
	do
	{
		std::cout << "Contact index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	} while (input.empty() || !std::isdigit(input[0]) || input.size() > 2 || std::stoi(input) > nb);
	this->_contacts[std::stoi(input)].info_complete();
}
