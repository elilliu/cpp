#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;
	delete i;

	const Cat*	k = new Cat();
	const Cat*	kbis = new Cat(*k);

	delete k;
	delete kbis;

	return (0);
}
