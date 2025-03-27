#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = *stringPTR;

	std::cout << "Memory adress of the string: " << &str << '\n';
	std::cout << "Memory adress of stringPTR: " << stringPTR << '\n';
	std::cout << "Memory adress of stringREF: " << &stringREF << '\n';

	std::cout << '\n';

	std::cout << "Value of the string: " << str << '\n';
	std::cout << "Value of stringPTR: " << *stringPTR << '\n';
	std::cout << "Value of stringREF: " << stringREF << '\n';
}
