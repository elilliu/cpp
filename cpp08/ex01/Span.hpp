#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	private:
		std::vector<int>	_tab;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		~Span();

		void	addNumber(int nb);

		class TabIsFullException: public std::exception {
			public:
				const char*	what() const throw() {
					return ("The tab is full, you can't add another element.");
				};
		};

		int	shortestSpan();
		int	longestSpan();

		class NotEnoughElementsException: public std::exception {
			public:
				const char*	what() const throw() {
					return ("There is not enough elements to calculate a distance.");
				};
		};
};

#endif
