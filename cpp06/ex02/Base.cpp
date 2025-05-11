#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	ran = rand() % 3;

	if (ran == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A);
	}

	else if (ran == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B);
	}

	else if (ran == 2)
	{
		std::cout << "Generated C" << std::endl;
		return (new C);
	}

	return (NULL);
}

void	identify(Base* p)
{
	std::cout << "Object p is type ";

	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "unkown";

	std::cout << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Object p is type ";

	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B";
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "C";
			}
			catch(const std::exception& e)
			{
				std::cout<< "unknown";
			}
		}
	}

	std::cout << std::endl;
}
