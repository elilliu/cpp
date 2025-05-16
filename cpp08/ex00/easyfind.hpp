#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class OccurrenceNotFoundException: public std::exception {
	public:
		const char*	what() const throw() {
			return ("The occurence wasn't found.");
		};
};

template <typename T>
void	easyfind(T& container, int nb) {
	typename T::iterator	it;

	std::cout << nb << ": " << std::ends;
	it = find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw OccurrenceNotFoundException();
	std::cout << "The occurence was found in the container.\n";
};

#endif
