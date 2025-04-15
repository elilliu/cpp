#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(const Animal& copy)
{
	this->_type = copy._type;
}

Animal&	Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Animal::~Animal(){}

void	Animal::makeSound() const
{
	std::cout << "Animal sound\n";
}
