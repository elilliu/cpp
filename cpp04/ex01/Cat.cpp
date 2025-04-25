#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "A cat has been created.\n";
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	*this = copy;
	std::cout << "A cat has been created by copying another cat.\n";
}

Cat&	Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = copy._brain;
	}
	std::cout << "A cat has been created via copy operator.\n";
	return (*this);
}

Cat::~Cat(){
	delete this->_brain;
	std::cout << "A cat has been destroyed.\n";
}

void	Cat::makeSound() const
{
	std::cout << "Miaou!\n";
}
