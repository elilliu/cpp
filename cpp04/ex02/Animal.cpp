#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "An animal has been created.\n";
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "An animal has been created by copying another animal.\n";
}

Animal&	Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "An animal has been created via copy operator.\n";
	return (*this);
}

Animal::~Animal(){
	std::cout << "An animal has been destroyed.\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound\n";
}

std::string	Animal::getType() const
{
	return (this->_type);
}
