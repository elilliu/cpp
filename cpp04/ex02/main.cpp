#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal*	i = new Cat();

	i->makeSound();

	delete i;

	return (0);
}
