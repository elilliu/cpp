#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		AMateria*	_materias[4];
		std::string	_name;
		AMateria*	_floor[10];

	public:
		Character();
		Character(const std::string name);
		Character(const Character& copy);
		Character&	operator=(const Character& copy);
		~Character();

		std::string const&	getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
