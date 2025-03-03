#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(Contact new);
		void	add();
		void	search;
	private:
		Contact	_contacts[8];
};

#endif
