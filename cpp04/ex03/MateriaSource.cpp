#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	(*this) = copy;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& copy) {
	if (this != &copy) {
		for (int i = 0; i < 4; i++) {
			delete (this->_materias[i]);
			this->_materias[i] = copy._materias[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete (this->_materias[i]);
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return ;
		}
	}

	std::cout << "You can't learn more materias." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}

	std::cout << "Unkown materia type." << std::endl;
	return (NULL);
}
