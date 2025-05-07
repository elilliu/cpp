#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern&	operator=(const Intern& copy);
		~Intern();

		AForm*	createShrubbery(const std::string target);
		AForm*	createRobotomy(const std::string target);
		AForm*	createPardon(const std::string target);

		AForm*	makeForm(std::string type, std::string target);

		typedef	AForm*(Intern::*fptr)(std::string target);
		fptr	whichForm(std::string type);

	private:
		struct s_entry
		{
			std::string	type;
			fptr		function;
		};

		s_entry	_allForms[3];
};

#endif
