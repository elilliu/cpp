#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "A weird cat has been created.\n";
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << "A weird cat has been created by copying another weird cat.\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "A weird cat has been created via copy operator.\n";
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "A weird cat has been destroyed.\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "*Weird cat gibberish*\n";
}
