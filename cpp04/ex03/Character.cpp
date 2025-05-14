#include "Character.hpp"

Character::Character() {
	this->_name = "Default";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(const std::string name): _name(name) {
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
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
}

std::string const&	Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx > 3)
		return ;
	this->_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx > 3)
		return ;

	if (this->_materias[idx])
		this->_materias[idx]->use(target);
}
