#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(const T* array, int len, void (*f)(const T))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
};

template <typename T>
void	print(const T element)
{
	std::cout << element << std::endl;
};

#endif
