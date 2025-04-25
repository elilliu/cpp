#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "A dog has been created.\n";
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	*this = copy;
	std::cout << "A dog has been created by copying another dog.\n";
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = copy._brain;
	}
	std::cout << "A dog has been created via copy operator.\n";
	return (*this);
}

Dog::~Dog(){
	delete this->_brain;
	std::cout << "A dog has been destroyed.\n";
}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
