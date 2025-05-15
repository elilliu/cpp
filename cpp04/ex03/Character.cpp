#include "Character.hpp"

Character::Character() {
	this->_name = "Default";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	for (int i = 0; i < 10; i++)
		this->_floor[i] = NULL;
}

Character::Character(const std::string name): _name(name) {
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	for (int i = 0; i < 10; i++)
		this->_floor[i] = NULL;
}

Character::Character(const Character& copy) {
	*this = copy;
}

Character&	Character::operator=(const Character& copy) {
	if (this != &copy) {
		this->_name = copy._name;
		for (int i = 0; i < 4; i++) {
			delete (this->_materias[i]);
			this->_materias[i] = copy._materias[i];
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete (this->_materias[i]);
	for (int i = 0; i < 10; i++)
		delete (this->_floor[i]);
}

std::string const&	Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	if (!m) {
		// std::cout << "Trying to equip non-existing materia." << std::endl;
		return ;
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (!this->_materias[i]) {
				this->_materias[i] = m;
				return ;
			}
		}
	}
}

void	Character::unequip(int idx) {
	if (idx > 3 || !this->_materias[idx]) {
		// std::cout << "Trying to unequip non-existing materia." << std::endl;
		return ;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!this->_floor[i]) {
				this->_floor[i] = this->_materias[idx];
				this->_materias[idx] = NULL;
				std::cout << "* drops " << this->_floor[i]->getType() << " on the floor *" << std::endl;
				return ;
			}
		}
		std::cout << "The floor is already full of materias! Please use the ones in your inventory." << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx > 3)
		return ;

	if (this->_materias[idx])
		this->_materias[idx]->use(target);
}
