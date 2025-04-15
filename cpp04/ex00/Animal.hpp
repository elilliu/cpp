#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	private:
		std::string	_type;
	public:
		Animal();
		Animal(const Animal& copy);
		Animal&	operator=(const Animal& copy);
		~Animal();
		virtual void	makeSound() const;
};

#endif
