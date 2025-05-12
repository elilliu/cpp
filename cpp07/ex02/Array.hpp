#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array(): _size(0) {
			this->_array = new T[this->_size];
		};

		Array(unsigned int n): _size(n) {
			this->_array = new T[this->_size];
		};

		Array(const Array& copy) {
			*this = copy;
		};

		Array&	operator=(const Array& copy) {
			if (this != &copy) {
				if (this->_array)
					delete[] this->_array;

				this->_size = copy._size;
				this->_array = new T[this->_size];

				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = copy._array[i];
			}
			return (*this);
		}

		~Array() {
			delete[] this->_array;
		}

		T&	operator[](unsigned int i) {
			if (i >= this->_size || !this->_array)
				throw IndexOutOfBoundException();
			return (this->_array[i]);
		}

		class IndexOutOfBoundException: public std::exception
		{
			public:
				const char*	what() const throw() {
					return ("Index is out of bound");
				};
		};

		unsigned int	size() const {
			return (this->_size);
		};
};

#endif
