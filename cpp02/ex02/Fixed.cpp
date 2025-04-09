#include "Fixed.hpp"



// CONSTRUCTORS //

Fixed::Fixed():_value(0){}

Fixed::Fixed(const int nb)
{
	this->_value = nb << this->_fract;
}

Fixed::Fixed(const float nb)
{
	this->_value = roundf(nb * (1 << this->_fract));
}



// COPY CONSTRUCTOR //

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
}



// COPY ASSIGNMENT (=) OPERATOR OVERLOAD //

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}



// DESTRUCTOR //

Fixed::~Fixed(){}



// GETTER AND SETTER //

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}



// CONVERSIONS //

float	Fixed::toFloat() const
{
	return (this->_value / (float)(1 << this->_fract));
}

int	Fixed::toInt() const
{
	return (this->_value >> this->_fract);
}



// INSERTION (<<) OPERATOR OVERLOAD //

std::ostream&	operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}



// COMPARISON OPERATORS OVERLOAD //

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}
bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}



// ARITHMETIC OPERATORS OVERLOAD //

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_value * other._value) >> this->_fract);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_value << this->_fract) / other._value);
	return (0);
}



// INCREMENT AND DECREMENT OPERATORS OVERLOAD //

Fixed&	Fixed::operator++()
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->_value;
	return (tmp);
}



// OVERLOADED MEMBER FUNCTIONS //

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}
