#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	michel("Michel", 5);

		std::cout << michel;
		michel.incrementGrade();
		std::cout << michel;

		std::cout << '\n';

		// Bureaucrat	sandrine("Sandrine", 150);

		// std::cout << sandrine;
		// sandrine.decrementGrade();
		// std::cout << sandrine;

		// Bureaucrat	sandrine("Sandrine", 1);

		// std::cout << sandrine;
		// sandrine.incrementGrade();
		// std::cout << sandrine;

		Bureaucrat	bob("Bob", -2);
		std::cout << bob;
	}

	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
