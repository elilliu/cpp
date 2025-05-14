#include "Ice.hpp"

Ice::Ice() {
	this->_type = "ice";
}

Ice::Ice(const Ice& copy) {
	*this = copy;
}

Ice&	Ice::operator=(const Ice& copy) {
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Ice::~Ice() {}

Ice*	Ice::clone() const {
	Ice*	clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


