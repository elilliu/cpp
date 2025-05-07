#include "Intern.hpp"

Intern::Intern()
{
	_allForms[0].function = &Intern::createShrubbery;
	_allForms[0].type = "shrubbery creation";

	_allForms[1].function = &Intern::createRobotomy;
	_allForms[1].type = "robotomy request";

	_allForms[2].function = &Intern::createPardon;
	_allForms[2].type = "presidential pardon";
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern&	Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern(){}

AForm*	Intern::createShrubbery(const std::string target)
{
	std::cout << "Intern creates a shrubbery creation form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(const std::string target)
{
	std::cout << "Intern creates a robotomy request form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPardon(const std::string target)
{
	std::cout << "Intern creates a presidential pardon form" << std::endl;
	return (new PresidentialPardonForm(target));
}

Intern::fptr	Intern::whichForm(std::string type)
{
	for (int i = 0; i < 3; i++)
	{
		if (_allForms[i].type == type)
			return (_allForms[i].function);
	}

	std::cout << "The form " << type << " doesn't exist" << std::endl;
	return (NULL);
}

AForm*	Intern::makeForm(std::string type, std::string target)
{
	fptr	ptrToFunction = whichForm(type);

	if (!ptrToFunction)
		return (NULL);
	return ((this->*ptrToFunction)(target));
}
