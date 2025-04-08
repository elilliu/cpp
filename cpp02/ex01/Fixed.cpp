#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = nb << this->_fract;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(nb * (1 << this->_fract));
}

Fixed::Fixed(const Fixed& nb)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = nb;
}

Fixed& Fixed::operator=(const Fixed& nb)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = nb.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_value / (float)(1 << this->_fract));
}

int	Fixed::toInt() const
{
	return (this->_value >> this->_fract);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& nb)
{
	out << nb.toFloat();
	return (out);
}
