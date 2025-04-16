#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << "A cat has been created.\n";
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "A cat has been created by copying another cat.\n";
}

Cat&	Cat::operator=(const Cat& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "A cat has been created via copy operator.\n";
	return (*this);
}

Cat::~Cat(){
	std::cout << "A cat has been destroyed.\n";
}

void	Cat::makeSound() const
{
	std::cout << "Miaou!\n";
}
