#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	michel("Michel", 5);
		Form		document("Very important paper", 4, 4);

		std::cout << michel;
		std::cout << '\n';
		std::cout << document;
		std::cout << '\n';

		michel.signForm(document);
		std::cout << '\n';

		michel.incrementGrade();

		std::cout << michel;
		std::cout << '\n';
		
		michel.signForm(document);
		std::cout << '\n';

		std::cout << document;
		std::cout << '\n';

		Form	document2("Nuclear codes", -10, -10);
		std::cout << document2;
	}

	catch (std::exception &except)
	{
		std::cerr << except.what() << std::endl;
	}

	return (0);
}
