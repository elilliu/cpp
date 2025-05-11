#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

bool	isPseudoF(std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	return (false);
}

bool	isPseudoD(std::string literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	return (false);
}

bool	checkError(std::string literal)
{
	if (isPseudoF(literal) || isPseudoD(literal))
	 	return (true);
	
	bool	hasNum = false;
	bool	hasChar = false;

	for (size_t i = 0; i < literal.size(); i++)
	{
		if (std::isdigit(literal[i]))
			hasNum = true;
		else if (literal[i] > 9 && literal[i] != '.' && literal[i] != 'f' && literal[i] != '-')
			hasChar = true;
	}
	
	return (((!hasNum || hasChar) && literal.size() > 1) ? false:true);
}

int	getType(std::string literal)
{
	if (isPseudoF(literal))
		return (2);
	if (isPseudoD(literal))
		return (3);
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return (0);
	if (literal.find('.') != std::string::npos && literal.size() > 1)
	{
		if (literal.find('f') != std::string::npos)
			return (2);
		return (3);
	}
	return (1);
}

void	toChar(std::string literal, long double ld)
{
	std::cout << "char: ";

	if (isPseudoD(literal) || isPseudoF(literal) || ld < 0 || ld > 255)
		std::cout << "impossible";
	else if (ld < 33 || ld > 127)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(ld) << "'";

	std::cout << std::endl;
}

void	toInt(std::string literal, long double ld)
{
	std::cout << "int: ";

	if (isPseudoD(literal) || isPseudoF(literal))
		std::cout << "impossible";
	else if (ld < std::numeric_limits<int>::min() || ld >  std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(ld);

	std::cout << std::endl;
}

void	toFloat(std::string literal, long double ld)
{
	std::cout << "float: ";

	if (isPseudoF(literal))
		std::cout << literal;
	else if (isPseudoD(literal))
		std::cout << literal + "f";
	else if (ld < -std::numeric_limits<float>::max() || ld > std::numeric_limits<float>::max())
		std::cout << "impossible";
	else
	{
		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(1) << static_cast<float>(ld) << "f";
	}

	std::cout << std::endl;
}

void	toDouble(std::string literal, long double ld)
{
	std::cout << "double: ";

	if (isPseudoD(literal))
		std::cout << literal;
	else if (isPseudoF(literal))
		std::cout << literal.substr(0, literal.size() - 1);
	else if (ld < -std::numeric_limits<double>::max() || ld > std::numeric_limits<double>::max())
		std::cout << "impossible";
	else
	{
		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(1) << ld;
	}

	std::cout << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	if (literal.empty() || !checkError(literal))
	{
		std::cerr << "Error" << std::endl;
		return ;
	}

	int	type = getType(literal);

	long double	ld;

	// std::cout << "c_str: " << literal.c_str() << std::endl;

	if (type == 0)
		ld = literal[0];
	else
		ld = atof(literal.c_str());

	// std::cout << "ld: " << ld << std::endl;

	if (type == 1 && (ld < std::numeric_limits<int>::min() || ld >  std::numeric_limits<int>::max()))
		type = 3;
	
	void	(*funcs[])(std::string, long double) = {toChar, toInt, toFloat, toDouble};
	std::string	types[4] = {"char", "int", "float", "double"};

	for (int i = 0; i < 4; i++)
	{
		if (type != i)
			funcs[i](literal, ld);
		else
			std::cout << types[i] << ": " << literal << std::endl;
	}
}
