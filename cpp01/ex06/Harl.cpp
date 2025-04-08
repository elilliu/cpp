#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::_debug()
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info()
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::filter(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i;
	for (i = 0; i < 4 && levels[i] != level; i++);

	switch (i)
	{
		case 0:
			this->_debug();

		case 1:
			this->_info();

		case 2:
			this->_warning();

		case 3:
			this->_error();
			break;

		case 4:
			std::cout << "Level of complaint not found" << std::endl;
			break;
	}
}
