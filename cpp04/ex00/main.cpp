#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	std::cout << '\n';

	std::cout << "j is a " << j->getType() << std::endl;
	std::cout << "i is a " << i->getType() << std::endl;
	std::cout << '\n';

	std::cout << j->getType() << " goes ";
	j->makeSound();

	std::cout << i->getType() << " goes ";
	i->makeSound();

	std::cout << "Random animal goes ";
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;

	std::cout << "\n\033[1;31m// Wrong animals //\033[0m\n\n";

	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongJ = new WrongCat();
	std::cout << '\n';

	std::cout << "wrongJ is a " << wrongJ->getType() << std::endl;
	std::cout << wrongJ->getType() << " goes ";
	wrongJ->makeSound();
	std::cout << std::endl;

	std::cout << "Wrong animal goes ";
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongJ;

	return (0);
}
