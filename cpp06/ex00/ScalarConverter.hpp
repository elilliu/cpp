#ifndef SCALARCONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include <stdlib.h>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter&	operator=(const ScalarConverter& copy);

	public:
		~ScalarConverter();
		static void	convert(std::string literal);
};

#endif
