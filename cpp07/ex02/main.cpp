#include "Array.hpp"

int	main()
{
	try
	{
		Array<std::string>	strArray(3);
		std::cout << "strArray size: " << strArray.size() << std::endl;
		strArray[1] = "Hello";
		std::cout << "strArray[0]: " << strArray[0] << std::endl;
		std::cout << "strArray[1]: " << strArray[1] << std::endl;

		std::cout << '\n';

		Array<int>	intArray(3);
		std::cout << "intArray size: " << intArray.size() << std::endl;
		intArray[0] = 2;
		intArray[2] = 42;
		std::cout << "intArray[0]: " << intArray[0] << std::endl;
		std::cout << "intArray[1]: " << intArray[1] << std::endl;
		std::cout << "intArray[2]: " << intArray[2] << std::endl;

		std::cout << "\nLet's try to call an index outside the bound.\n";
		std::cout << intArray[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
