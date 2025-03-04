#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <unistd.h>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	add();
		void	display();

	private:
		Contact	_contacts[8];
		int	_book_size;
};

#endif
