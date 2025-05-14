#include "Cure.hpp"

Cure::Cure() {
	this->_type = "cure";
}

Cure::Cure(const Cure& copy) {
	*this = copy;
}

Cure&	Cure::operator=(const Cure& copy) {
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Cure::~Cure() {}

Cure*	Cure::clone() const {
	Cure*	clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
