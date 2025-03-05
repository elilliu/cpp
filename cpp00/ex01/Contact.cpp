#include "Contact.hpp"

Contact::Contact()
{
	this->_index = 0;
}

Contact::Contact(int nb)
{
	this->_index = nb;

	std::cout << "First name: ";
	std::getline(std::cin, this->_firstname);

	std::cout << "Last name: ";
	std::getline(std::cin, this->_lastname);

	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nickname);

	do
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, this->_phone_number);
	} while (!this->valid_number(_phone_number));

	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->_darkest_secret);
}

int	Contact::valid_number(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}

void	Contact::info_summary()
{
	std::cout << "        " << this->_index << " |";

	if (this->_firstname.size() > 8)
		std::cout << " " << this->_firstname.substr(0, 8) << ".|";
	else
	{
		std::cout << std::setw(11);
		std::cout << this->_firstname + " |";
	}

	if (this->_lastname.size() > 8)
		std::cout << " " << this->_lastname.substr(0, 8) << ".|";
	else
	{
		std::cout << std::setw(11);
		std::cout << this->_lastname + " |";
	}

	if (this->_nickname.size() > 8)
		std::cout << " " << this->_nickname.substr(0, 8) << ".";
	else
	{
		std::cout << std::setw(9);
		std::cout << this->_nickname;
	}

	std::cout << std::endl;
}

void	Contact::info_complete()
{
	std::cout << "First name: " << this->_firstname << std::endl;
	std::cout << "Last name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
	std::cout << std::endl;
}
