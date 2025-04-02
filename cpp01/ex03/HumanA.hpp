#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_Weapon;
	public:
		HumanA(std::string name, Weapon& Weapon);
		~HumanA();
		void	attack();
};

#endif
