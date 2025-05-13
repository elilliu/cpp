#include "AMateria.hpp"

AMateria::AMateria(): _type("Default") {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(const AMateria& copy) {
	*this = copy;
}

AMateria&	AMateria::operator=(const AMateria& copy) {
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

AMateria::~AMateria(){}

std::string const&	AMateria::getType() const {
	return (this->_type);
}

AMateria*	AMateria::clone() const {
	return ((AMateria*)this);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* uses a materia on " << target.getName() << " *" << std::endl;
}
