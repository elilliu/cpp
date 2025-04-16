#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "A dog has been created.\n";
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "A dog has been created by copying another dog.\n";
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		std::cout << "A dog has been created via copy operator.\n";
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "A dog has been destroyed.\n";
}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
