#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	public:
		Contact();
		Contact(int nb);
		void	info_summary();
		void	info_complete();

	private:
		int			_index;
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int	valid_number(std::string str);
};

#endif
