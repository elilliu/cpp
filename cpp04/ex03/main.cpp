#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int	main()
{
	std::cout << "***** 42's main *****\n" << std::endl;

	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "\n\n***** Additionnal tests *****\n" << std::endl;

	IMateriaSource*	grimoire = new MateriaSource();
	grimoire->learnMateria(new Ice());
	// grimmoire->learnMateria(new AMateria());
	grimoire->learnMateria(new Ice());
	grimoire->learnMateria(new Cure());
	grimoire->learnMateria(new Ice());
	grimoire->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter*	newMe = new Character("newMe");
	tmp = grimoire->createMateria("cure");
	newMe->equip(tmp);
	tmp = grimoire->createMateria("i don't exist");
	newMe->equip(tmp);
	std::cout << std::endl;
	tmp = grimoire->createMateria("ice");
	newMe->equip(tmp);
	tmp = grimoire->createMateria("cure");
	newMe->equip(tmp);
	tmp = grimoire->createMateria("cure");
	newMe->equip(tmp);
	tmp = grimoire->createMateria("cure");
	newMe->equip(tmp);

	ICharacter*	john = new Character("john");

	newMe->use(0, *john);
	newMe->use(1, *john);
	newMe->use(2, *john);
	newMe->use(3, *john);
	newMe->use(4, *john);

	std::cout << std::endl;

	newMe->unequip(0);
	newMe->unequip(0);
	newMe->unequip(4);
	newMe->unequip(1);

	delete newMe;
	delete john;
	delete grimoire;
	delete tmp;

	return 0;
}
