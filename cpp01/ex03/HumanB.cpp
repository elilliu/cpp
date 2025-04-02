#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& Weapon)
{
	this->_Weapon = &Weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_Weapon->getType() << '\n';
}
