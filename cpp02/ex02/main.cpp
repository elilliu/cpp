#include "Fixed.hpp"

int	main()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "a: " << a << " (" << a.getRawBits() << ")" << std::endl;
	std::cout << "++a: " << ++a << " (" << a.getRawBits() << ")" << std::endl;
	std::cout << "a: " << a << " (" << a.getRawBits() << ")" << std::endl;
	std::cout << "a++: " << a++ << " (" << a.getRawBits() << ")" << std::endl;
	std::cout << "a: " << a << " (" << a.getRawBits() << ")" << std::endl;

	std::cout << "b: " << b << " (" << b.getRawBits() << ")" << std::endl;

	std::cout << "maximum of a and b: " << Fixed::max(a, b) << std::endl;

	return (0);
}
