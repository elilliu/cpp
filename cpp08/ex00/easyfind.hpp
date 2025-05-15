#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class OccurrenceNotFoundException: public std::exception {
	public:
		const char*	what() const throw() {
			return ("The occurence wasn't found.");
		};
};

template <typename T>
void	easyfind(T& container, int nb) {
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

#endif
