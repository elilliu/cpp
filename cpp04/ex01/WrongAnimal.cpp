#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "A weird animal has been created.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->_type = copy._type;
	std::cout << "A weird animal has been created by copying an other weird animal.\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "A weird animal has been created via copy operator.\n";
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "A weird animal has been destroyed.\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Weird animal gibberish*\n";
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
