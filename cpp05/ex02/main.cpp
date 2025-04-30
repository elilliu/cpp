#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		std::cout << "TEST 1\n\n";

		Bureaucrat	michel("Michel", 5);
		ShrubberyCreationForm	shrubForm("Garden");

		std::cout << michel;
		std::cout << '\n';
		std::cout << shrubForm;
		std::cout << '\n';

		michel.signForm(shrubForm);
		michel.executeForm(shrubForm);

		std::cout << "\n-------------------------------------\n\n";
		std::cout << "TEST 2\n\n";

		Bureaucrat	herve("Hervé", 62);
		RobotomyRequestForm	robotForm("The subject of the experiment");

		std::cout << herve;
		std::cout << michel;
		std::cout << '\n';
		std::cout << robotForm;
		std::cout << '\n';

		michel.executeForm(robotForm);
		herve.signForm(robotForm);
		herve.executeForm(robotForm);
		michel.executeForm(robotForm);

		std::cout << "\n-------------------------------------\n\n";
		std::cout << "TEST 3\n\n";

		PresidentialPardonForm	presForm("The sinner");

		std::cout << herve;
		std::cout << michel;
		std::cout << '\n';
		std::cout << presForm;
		std::cout << '\n';

		herve.executeForm(presForm);
		herve.signForm(presForm);
		michel.signForm(presForm);
		herve.executeForm(presForm);
		michel.executeForm(presForm);

		std::cout << "\n-------------------------------------\n\n";

		Bureaucrat	tooGoodToBeTrue("Dream", -2);

		std::cout << tooGoodToBeTrue;
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
