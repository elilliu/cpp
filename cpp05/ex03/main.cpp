#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	yourAwesomeIntern;
	AForm*	rrf;

	rrf = yourAwesomeIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;

	std::cout << '\n';

	Bureaucrat	michel("Michel", 5);

	michel.executeForm(*rrf);
	michel.signForm(*rrf);
	michel.executeForm(*rrf);

	delete (rrf);

	std::cout << '\n';

	AForm*	nonExistingForm;

	nonExistingForm = yourAwesomeIntern.makeForm("undefined type", "target");

	delete (nonExistingForm);

	return (0);
}
