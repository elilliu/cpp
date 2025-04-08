#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fract;
	public:
		Fixed();
		Fixed(Fixed& nb);
		Fixed& operator=(const Fixed& nb);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
