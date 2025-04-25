#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();


	delete j;
	delete i;

	std::cout << '\n';

	const Animal*	flock[10];

	for (int i = 0; i < 5; i++)
		flock[i] = new Dog();
	for (int i = 5; i < 10; i++)
		flock[i] = new Cat();
	
	std::cout << '\n';

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " is a " << flock[i]->getType() << std::endl;
		flock[i]->makeSound();
	}

	std::cout << '\n';

	for (int i = 0; i < 10; i++)
		delete flock[i];

	std::cout << '\n';

	const Animal*	random = new Animal();

	random->makeSound();

	delete random;

	return (0);
}
