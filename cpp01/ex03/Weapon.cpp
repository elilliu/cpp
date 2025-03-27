#include "Weapon.hpp"

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
